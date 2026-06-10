-- ALTER DATABASE [Simple Query] SET SINGLE_USER WITH ROLLBACK IMMEDIATE;
-- ALTER DATABASE [Simple Query] COLLATE Latin1_General_100_CI_AS_SC_UTF8;
-- ALTER DATABASE [Simple Query] SET MULTI_USER;

INSERT INTO KHOAHOC(MAKH, TENKH, NGAYBD, NGAYKT) VALUES
('K001','Khóa 1','2020-01-10','2020-03-20'),
('K002','Khóa 2','2020-02-28','2020-05-28'),
('K003','Khóa 3','2020-04-10','2020-07-20'),
('K004','Khóa 4','2020-06-15','2020-09-20');

INSERT INTO CHUONGTRINH(MACT, TENCT) VALUES
('CT001','Tiếng Anh Tổng Quát'),
('CT002','Tiếng Anh Trẻ Em'),
('CT003','Tiếng Anh Luyện Kỹ Năng'),
('CT004','Chương Trình TOEIC'),
('CT005','Tiếng Anh IELTS'),
('CT006','Chương trình CamBridge'),
('CT007','Chứng Chỉ Tiếng Anh 6 Bậc(A1,B1,B2,C1)');

INSERT INTO LOAILOP(MALOAI, MACT, TENLOAI) VALUES
('LL001','CT001','Tiếng Anh căn bản'),
('LL002','CT001','Tiếng Anh A1'),
('LL003','CT001','Tiếng Anh A2'),
('LL004','CT001','Tiếng Anh B1'),
('LL005','CT001','Tiếng Anh B2'),
('LL006','CT001','Tiếng Anh C1'),
('LL007','CT001','Tiếng Anh C2'),
('LL008','CT001','Tiếng Anh nâng cao'),
('LL009','CT002','Anh văn nhi đồng'),
('LL010','CT002','Anh văn thiếu nhi'),
('LL011','CT002','Anh văn thiếu niên'),
('LL012','CT002','Tiếng Anh Tổng Quát dành cho thiếu niên(B1)'),
('LL013','CT002','Tiếng Anh Tổng Quát dành cho thiếu niên(B1+)'),
('LL014','CT002','Tiếng Anh nâng cao'),
('LL015','CT002','IELTS');

INSERT INTO LOP(MALOP, MALOAI, TENLOP, SISO, MAKH) VALUES
('L001','LL001','Lớp 1','30','K001'),
('L002','LL001','Lớp 2','30','K002'),
('L003','LL002','Lớp 1','25','K003'),
('L004','LL002','Lớp 2','25','K004'),
('L005','LL003','Lớp 1','20','K001'),
('L006','LL003','Lớp 2','20','K002'),
('L007','LL004','Lớp 1','15','K003'),
('L008','LL004','Lớp 2','15','K004'),
('L009','LL005','Lớp 1','13','K001'),
('L010','LL012','Lớp 2','15','K002'),
('L011','LL006','Lớp 1','20','K003'),
('L012','LL012','Lớp 2','18','K004');

INSERT INTO HOCVIEN(MAHV, TENHV, NGAYSINH, GIOITINH, SDT, DIACHI) VALUES
('HV001','Nguyễn Văn A','2000-01-01','Nam','0901234567','Hà Nội'),
('HV002','Trần Thị B','2001-02-15','Nữ','0901234568','Hồ Chí Minh'),
('HV003','Lê Văn C','1999-03-20','Nam','0901234569','Đà Nẵng'),
('HV004','Phạm Thị D','2002-04-10','Nữ','0901234570','Hải Phòng'),
('HV005','Hoàng Văn E','2000-05-25','Nam','0901234571','Cần Thơ'),
('HV006','Đỗ Thị F','2001-06-30','Nữ','0901234572','Nha Trang'),
('HV007','Vũ Văn G','1998-07-15','Nam','0901234573','Huế'),
('HV008','Phan Thị H','2002-08-20','Nữ','0901234574','Vũng Tàu');

INSERT INTO PHIEUTHU(SOPT, MAHV, MALOP, NGAYLAPPHIEU, THANHTIEN) VALUES
('PT001','HV001','L001','2021-06-07',500000),
('PT002','HV002','L002','2021-06-09',500000),
('PT003','HV003','L003','2020-01-25',500000),
('PT004','HV004','L001','2020-02-10',500000),
('PT005','HV005','L002','2020-02-15',500000),
('PT006','HV006','L003','2020-02-20',500000),
('PT007','HV007','L001','2020-03-05',500000),
('PT008','HV008','L002','2020-03-10',500000);

INSERT INTO MONHOC(MAMH, TENMH) VALUES
('MH001','Ngữ pháp'),
('MH002','Từ vựng'),
('MH003','Kỹ năng giao tiếp');

INSERT INTO DIEM(MAMH, MAHV, MALOP, DIEM) VALUES
('MH001','HV001','L001',8.5),
('MH002','HV001','L001',7.0),
('MH003','HV001','L001',9.0),
('MH001','HV002','L002',6.5),
('MH002','HV002','L002',8.0),
('MH003','HV002','L002',7.5),
('MH001','HV003','L003',9.0),
('MH002','HV003','L003',8.5),
('MH003','HV003','L003',9.5),
('MH001','HV004','L001',7.0),
('MH002','HV004','L001',6.5),
('MH003','HV004','L001',8.0),
('MH001','HV005','L002',8.0),
('MH002','HV005','L002',7.5),
('MH003','HV005','L002',9.0),
('MH001','HV006','L003',6.5),
('MH002','HV006','L003',7.0),
('MH003','HV006','L003',8.5),
('MH001','HV007','L001',9.0),
('MH002','HV007','L001',8.5),
('MH003','HV007','L001',9.5),
('MH001','HV008','L002',7.5),
('MH002','HV008','L002',6.0),
('MH003','HV008','L002',8.0);