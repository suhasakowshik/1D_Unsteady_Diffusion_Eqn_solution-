%%

x1=importdata("data0.dat");
x2=importdata("data100.dat");
x3=importdata("data500.dat");
x4=importdata("data1000.dat");
x5=importdata("avgError.dat");
%%
x=linspace(0,1,128);
t=linspace(0,0.15006,15006);
%%
figure (1)
plot(x,x1,'-r',x,x2,'--r',x,x3,'-b',x,x4,'--b',"LineWidth",1.5);
set(gca,'FontSize',12);
ylabel("u",'FontSize',14);
xlabel("x",'FontSize',14);
legend("at 0s","at 0.001s"," at 0.005s","at 0.01s","Location","southwest","FontSize",12);
%print('-dpng','-r700','Uvalues.png')
%%
figure (2)
plot(t,x5,'-r',"LineWidth",1.5);
set(gca,'FontSize',12);
ylabel("Average Error",'FontSize',14);
xlabel("t (s)",'FontSize',14);
print('-dpng','-r700','avgError.png')
%%