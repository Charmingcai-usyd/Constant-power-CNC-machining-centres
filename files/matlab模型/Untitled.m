close all; clear all; clc
D=xlsread('��������.xlsx','Sheet1');
Y1_SP=D(1:177,4);
Y1_KZ=D(1:177,5);
Y2_SP=D(1:323,6);
Y2_KZ=D(1:323,7);
Y1_SUM=D(41:125,5);%�����
Y2_SUM=D(41:140,7);%�����
a=sum(Y1_SUM);%ͳ�����1
b=sum(Y2_SUM);%ͳ�����2
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
legend('δ����㹦��ģ�����ƹ���','δ����㹦��ģ�����ƿ��Ʊ���');
hold on;
xlabel('ʱ��t');
ylabel('��ֵA');
figure(2);
plot(X2,Y2_SP,'LineWidth',2,'Color','m');
hold on;
plot(X2,Y2_KZ,'LineWidth',2,'Color','g');
hold on;
plot([41,41],[1,1200],'LineWidth',2,'Color','r');
plot([140,140],[1,1200],'LineWidth',2,'Color','r');
plot([0,323],[640,640],'LineWidth',2,'Color','b');
legend('����㹦��ģ�����ƹ���','����㹦��ģ�����ƿ��ƽ�������');
hold on;
xlabel('ʱ��t');
ylabel('��ֵL');
figure(3);
plot(X2,Y2_KZ,'LineWidth',2,'Color','b');
hold on;
plot(X1,Y1_KZ,'LineWidth',2,'Color','r');
hold on;
legend('δ����㹦��','����㹦��');
disp('�����Թ����и��������'); 
if(a>=b)
disp('δ����㹦�ʿ��Ʋ����Ĺ��ʸ�'); 
end
if(a<b)
disp('����㹦�ʿ��Ʋ����Ĺ��ʸ�'); 
end