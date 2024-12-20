# Plant-Water

Dự án Smart Irrigation với ESP32 và MQTT là một hệ thống tưới tiêu thông minh sử dụng ESP32 để giám sát độ ẩm đất và tự động điều khiển việc tưới dựa trên dữ liệu từ cảm biến. 
Hệ thống này sử dụng MQTT để truyền tải dữ liệu giữa ESP32 và ứng dụng, cho phép giám sát và điều khiển từ xa qua điện thoại di động hoặc web

# Yêu cầu phần cứng
* ESP32: Là bộ vi điều khiển chính, có khả năng kết nối Wi-Fi để truyền dữ liệu.
** ESP32-DevKitC-32E 
  https://www.espressif.com/en/products/devkits/esp32-devkitc/     .
** ESP32 Expansion Board**
  https://grabcad.com/library/esp32-expansion-board-esp32-shield-development-board-1

* Cảm biến độ ẩm đất điện dung: Gravity: Analog Capacitive Soil Moisture Sensor - Corrosion Resistant: PPDF-SEN0193
* Rơ-le hoặc Module bơm: Để điều khiển máy bơm nước.
* Bơm nước: Để tưới nước khi cần thiết.
# Các thành phần phần mềm
* Firmware ESP32: Được lập trình bằng Arduino IDE hoặc PlatformIO.
* MQTT Broker:  Làm nhiệm vụ nhận và phân phối các thông báo từ ESP32 đến ứng dụng và ngược lại. (Xây Dựng Máy Chủ MQTT Cục Bộ với Mosquitto hoặc Sử Dụng Máy Chủ Trực Tuyến như HiveMQ)
* Ứng dụng di động (tùy chọn): Được xây dựng bằng Flutter hoặc một nền tảng tương tự, cho phép giám sát và điều khiển hệ thống từ xa.
# Kiến trúc tổng quan
* ESP32:  
  Ở chế độ AP: Chờ nhận thông tin WiFi từ ứng dụng Flutter.  
  Ở chế độ STA: Kết nối với mạng WiFi và giao tiếp với MQTT broker.  
* Flutter:  
  Giai đoạn 1: Gửi thông tin WiFi qua HTTP POST tới ESP32 trong chế độ AP.  
  Giai đoạn 2: Kết nối với MQTT broker và lắng nghe/truyền dữ liệu với ESP32 qua broker.
