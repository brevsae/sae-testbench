1;
% Prevent Octave from thinking that this
% is a function file:
%Authors:	Edgar Tejada
%			Marqose Saephan
%Date provided by FSAE TTC
%from fsaettc.org
%Loading run 8, which was testing corner turning zero camber and regulated tire pressure to 82 kPa.

tireDataMat = load("TireData/B1654run8.mat");

%stores the time data
timeVector =  tireDataMat.ET;
%Latteral force vector
longitudinalFX = tireDataMat.FX;
latteralFY = tireDataMat.FY;
normFZ = tireDataMat.FZ;
figure(1);
hold on;
plot(timeVector,latteralFY,'r','Linewidth',2)
xlabel('Time (s)');
ylabel('Lateral Force (N)');

figure(2);
hold on;
%Lateral force as a function of Slip angle (in degrees) 
plot(tireDataMat.SA, latteralFY,'b','Linewidth',2)
xlabel('Slip Angle (Degrees)');
ylabel('Lateral Force (N)');

%%Plotting FZ, will be used as 3rd dimension in a bit.
figure(3);
hold on;
plot(timeVector,normFZ,'g','Linewidth',2)
xlabel('Time (s)');
ylabel('Normal Force (N)');

figure(4)
hold on;
%plot(longitudinalFX,latteralFY)
length(normFZ)
length(latteralFY)
length(longitudinalFX)
%%Goal: Force response in relation to slip angle (SA) and other inputs!

%Test comment
