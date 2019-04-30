% User Input
U_0 = input('Enter the cell voltage in Volts: ');
U_max = input('Enter the maximum cell voltage in Volts: ');
C_0 = input('Enter the cell capacity: '); 
m = input ('Enter the mass of each cell: '); 
V = input('Enter the volume of each cell: '); 
I_max = input('Enter the peak discharge current: '); 

UserInputArray = [U_0 U_max C_0 m V I_max]; 

% Calculations Pt. 1
% Cell Energy (kWh)
E_0 = C_0*U_max; 

% Max Output Power (kW)
P_max = U_0*I_max;

% Volumetric Energy Density (kWh/m^3)
E_V = E_0/V;

% Gravimetric Energy Density (kWh/m^3)
E_m = E_0/m;

% Battery Max
P_Bmax = 80;
U_Bmax = 600;
U_Smax = 120;
E_Bmax = 6;

%Calculations Pt. 2
% Maximum number of serial cells limited by voltage
N_Umax = U_Smax/U_max; 

% Maximum number of serial cells limited by power 
N_Pmax = E_Bmax/E_0; 

% Maximum number of serial cells from the max battery voltage
N_SE = U_Bmax/E_0; 

% Maximum number of serial cells from the max battery output power
N_PS = P_Bmax/(U_max*N_SE*I_max);

% Calculating the number of serial segments
% k1 depends on N_Umax
k1 = N_Umax;
% k2 depends on N_Pmax
k2 = N_Pmax;
if k1 <= k2
    n_ss = N_SE/k1;
else
    n_ss = N_SE/k2;
end

n_Ss = N_SE/k1; 