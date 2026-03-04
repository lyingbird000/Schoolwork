# 1.概述
- 用c++简单实现一个员工管理系统，实现增删改查和文件读写功能，Staff和StaffSystem类图见附图
# 2.知识点
综合运用本学期课程中学到的面向对象知识，包括：
- 对现实个体的对象化
- 读取与修改成员数据方法的规范化
- 将成员数据与文件数据进行交互
# 3.调试运行
- 需将附的测试文件`test_staff_data.txt`和`staff_data.txt`与几个代码文件放在一个文件夹，再用一般的编译软件运行即可
- 终端运行见附图
- 测试文件变化：
运行前：
```
test_staff_data:
0 1 Alice 90 ProjectX
1 2 Bob 95 ProjectX

staff_data:

0 0601 GouCong 1266 XiangMuJia
0 0012 SunWei 7000 XiangMuJia
0 1056 YueFei 3666 XiangMuYi
0 1008 TouCheng 6226 XiangMuYi
1 0002 WangChe 8899 XiangMuJia
0 0008 WangBing 8400 XiangMuYi
0 0005 GouDong 7300 XiangMuJia
1 0003 YuWenChengDu 9999 XiangMuYi
```

运行后：
```
test_staff_data:
1 2 Bob 95 ProjectX

staff_data:
0 0601 GouCong 1266 XiangMuJia
0 0012 SunWei 7000 XiangMuJia
0 1056 YueFei 3666 XiangMuYi
0 1008 TouCheng 6226 XiangMuYi
1 0002 WangChe 8899 XiangMuJia
0 0008 WangBing 8400 XiangMuYi
1 0003 YuWenChengDu 9999 XiangMuYi
```
# 4.改进方向
- 后续数据量增大时，可以联系数据库知识，将这个简单的信息管理系统正式化