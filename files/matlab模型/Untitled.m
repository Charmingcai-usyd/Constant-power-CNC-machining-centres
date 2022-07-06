close all; clear all; clc
D=xlsread('验收数据.xlsx','Sheet1');
Y1_SP=D(1:177,4);
Y1_KZ=D(1:177,5);
Y2_SP=D(1:323,6);
Y2_KZ=D(1:323,7);
Y1_SUM=D(41:125,5);%求面积
Y2_SUM=D(41:140,7);%求面积
a=sum(Y1_SUM);%统计面积1
b=sum(Y2_SUM);%统计面积2
disp('a=');
disp(a);
disp('b=');
disp(b);
X1=1:1:177;
X2=1:1:323;
X3=1:1:85;
figure(1);
plot(X1,Y1_KZ,'LineWidth',2,'Color',[.6 0 0]);
hold on;
plot(X1,Y1_SP,'LineWidth',2,'Color','c');
hold on;
plot([41,41],[1,1200],'LineWidth',2,'Color','r');
plot([125,125],[1,1200],'LineWidth',2,'Color','r');
plot([0,177],[640,640],'LineWidth',2,'Color','b');
legend('未加入恒功率模糊控制功率','未加入恒功率模糊控制控制倍率');
hold on;
xlabel('时间t');
ylabel('幅值A');
figure(2);
plot(X2,Y2_SP,'LineWidth',2,'Color','m');
hold on;
plot(X2,Y2_KZ,'LineWidth',2,'Color','g');
hold on;
plot([41,41],[1,1200],'LineWidth',2,'Color','r');
plot([140,140],[1,1200],'LineWidth',2,'Color','r');
plot([0,323],[640,640],'LineWidth',2,'Color','b');
legend('加入恒功率模糊控制功率','加入恒功率模糊控制控制进给倍率');
hold on;
xlabel('时间t');
ylabel('幅值L');
figure(3);
plot(X2,Y2_KZ,'LineWidth',2,'Color','b');
hold on;
plot(X1,Y1_KZ,'LineWidth',2,'Color','r');
hold on;
legend('未加入恒功率','加入恒功率');
disp('经过对功率切割面积积分'); 
if(a>=b)
disp('未加入恒功率控制产生的功率高'); 
end
if(a<b)
disp('加入恒功率控制产生的功率高'); 
end