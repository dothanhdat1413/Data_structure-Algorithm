## Bài 1
Quản lý sinh viên của một trường đại học dùng danh sách liên kết đơn. Mỗi sinh viên có nhiều thông tin cần quản lý, tuy nhiên, trong bài tập này, để cho đơn giản ta chỉ quản lý các thông tin sau: Mã sinh viên, họ tên, giới tính, ngày tháng năm sinh, địa chỉ, lớp và khoa. Viết chương trình cài đặt thực hiện các yêu cầu sau 
1. Khai báo cấu trúc dữ liệu cho bài toán.
2. Nhập vào Danh sách sinh viên ListSV, và in ra Danh sách sinh viên được sắp xếp tăng dần theo mã sinh viên. Hãy viết hàm thêm một sinh viên mới vào danh sách ListSV  đã sắp xếp và SV được sắp xếp theo đúng thứ tự ở DS mới.
3. In ra các sinh viên có cùng ngày sinh, nếu không tìm thấy sinh viên có cùng ngày sinh thì in thông báo “không tìm thấy sinh viên cùng ngày sinh”
4. Loại bỏ các sinh viên có cùng ngày sinh ra khỏi danh sách ListSV

## Bài 2
Bài toán Josephus được mô tả như sau: Có N người đánh số từ 1 đến N ngồi xếp thành vòng tròn. Người bắt đầu là người số 1 giữ một quả bóng và truyền cho người thứ 2, người thứ 2 truyền bóng cho người thứ 3 theo 1 chiều nhất định và lần lượt đến khi truyền đến người thứ M, người thứ M sẽ bị loại ra khỏi vòng tròn. Vòng tròn sẽ bị thu hẹp dần, cuộc chơi vẫn tiếp tục với người ngồi kế tiếp người thứ M vừa bị loại bỏ, sẽ là người giữ quả bóng cho lượt chơi tiếp theo và được coi là người số 1 của lượt tiếp theo. Người cuối cùng còn sót lại là người chiến thắng. 
Ví dụ như sau: 
-	Nếu N = 5, M = 0, các người chơi bị loại bỏ là 1, 2, ,3 ,4 người 5 là người chiến thắng
-	Nếu N = 5, M = 1, thì thứ tự người chơi bị loại bỏ là 2, 4, 1, 5 người 3 là người chiến thắng 
Yêu cầu: 
1. Thiết kế giải thuật để tìm ra người chiến thắng cuối cùng, viết chương trình cài đặt giải thuật bằng việc sử dụng cấu trúc dữ liệu kiểu danh sách liên kết để duyệt luật chơi và tìm được vị trí người chiến thắng với các trường hợp của M = 1,2,3 và N bất kỳ 

Tạo Node có giá trị là số thứ tự của người chơi
Duyệt qua các node và đếm từ 1 tới M, khi tới M rồi thì xóa node đó và tiếp tục cho đến khi chỉ còn 1 người

-> độ phức tạp thuật toán là M*N!

2. Nếu M = 1, xác định độ phức tạp thuật toán tương ứng với giải thuật đã đề xuất, tính thời gian chạy chương trình với giá trị N > 100000
