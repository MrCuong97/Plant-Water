# Plant-Water

Dự án Smart Irrigation với ESP32 và MQTT là một hệ thống tưới tiêu thông minh sử dụng ESP32 để giám sát độ ẩm đất và tự động điều khiển việc tưới dựa trên dữ liệu từ cảm biến. 
Hệ thống này sử dụng MQTT để truyền tải dữ liệu giữa ESP32 và ứng dụng, cho phép giám sát và điều khiển từ xa qua điện thoại di động hoặc web

# Yêu cầu phần cứng
* ESP32: Là bộ vi điều khiển chính, có khả năng kết nối Wi-Fi để truyền dữ liệu.
* Cảm biến độ ẩm đất: Để đo độ ẩm đất.
* Rơ-le hoặc Module bơm: Để điều khiển máy bơm nước.
* Bơm nước: Để tưới nước khi cần thiết.
* MQTT Broker: Có thể sử dụng Mosquitto MQTT broker hoặc broker đám mây như HiveMQ, Adafruit IO, hoặc một dịch vụ MQTT miễn phí.
# Các thành phần phần mềm
* Firmware ESP32: Được lập trình bằng Arduino IDE hoặc PlatformIO.
* MQTT Broker:  Làm nhiệm vụ nhận và phân phối các thông báo từ ESP32 đến ứng dụng và ngược lại.
  Xay dung may chu cho mang cuc bo voi (Mosquitto MQTT broker) hoac su dung cac may chu truc tuyen nhu HiveMQ
* Ứng dụng di động (tùy chọn): Được xây dựng bằng Flutter hoặc một nền tảng tương tự, cho phép giám sát và điều khiển hệ thống từ xa.
