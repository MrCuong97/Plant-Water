#include <WiFi.h>
#include <PubSubClient.h>

// Cấu hình WiFi
const char* ssid = "Your_SSID";
const char* password = "Your_PASSWORD";

// Cấu hình MQTT
const char* mqtt_server = "broker.hivemq.com"; // Thay bằng MQTT broker của bạn
const int mqtt_port = 1883;
const char* mqtt_topic_moisture = "irrigation/moisture";
const char* mqtt_topic_control = "irrigation/control";

WiFiClient espClient;
PubSubClient client(espClient);

// Cấu hình chân
const int moisturePin = 34; // Chân nối với cảm biến độ ẩm
const int relayPin = 26;    // Chân nối với rơ-le điều khiển bơm

// Giá trị ngưỡng độ ẩm
int moisture_threshold = 500; // Điều chỉnh giá trị này tùy thuộc vào loại đất

void setup() {
  Serial.begin(115200);

  // Cấu hình chân
  pinMode(moisturePin, INPUT);
  pinMode(relayPin, OUTPUT);
  digitalWrite(relayPin, LOW);

  // Kết nối WiFi
  setup_wifi();

  // Cấu hình MQTT
  client.setServer(mqtt_server, mqtt_port);
  client.setCallback(callback);
}

void setup_wifi() {
  delay(10);
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("WiFi connected");
}

void callback(char* topic, byte* message, unsigned int length) {
  Serial.print("Message received on topic: ");
  Serial.println(topic);
  String messageTemp;
  
  for (int i = 0; i < length; i++) {
    messageTemp += (char)message[i];
  }
  
  if (String(topic) == mqtt_topic_control) {
    if (messageTemp == "ON") {
      digitalWrite(relayPin, HIGH);
    } else if (messageTemp == "OFF") {
      digitalWrite(relayPin, LOW);
    }
  }
}

void reconnect() {
  while (!client.connected()) {
    Serial.print("Attempting MQTT connection...");
    if (client.connect("ESP32Client")) {
      Serial.println("connected");
      client.subscribe(mqtt_topic_control);
    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      delay(5000);
    }
  }
}

void loop() {
  if (!client.connected()) {
    reconnect();
  }
  client.loop();

  int moistureValue = analogRead(moisturePin);
  Serial.print("Moisture level: ");
  Serial.println(moistureValue);

  // Tự động điều khiển bơm
  if (moistureValue < moisture_threshold) {
    digitalWrite(relayPin, HIGH);
  } else {
    digitalWrite(relayPin, LOW);
  }

  // Gửi dữ liệu độ ẩm qua MQTT
  String moistureStr = String(moistureValue);
  client.publish(mqtt_topic_moisture, moistureStr.c_str());
  
  delay(2000); // Đo độ ẩm mỗi 2 giây
}
