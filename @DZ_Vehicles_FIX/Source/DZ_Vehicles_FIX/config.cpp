#define _ARMA_

// ============================================================
// Патч поверх ванильных машин DayZ (DZ_Vehicles_Wheeled).
// Оригинальный файл игры НЕ трогаем - только наследуемся от
// существующих классов и переопределяем физику.
//
// Покрыты все спавнящиеся варианты (включая цветовые):
// CivilianSedan (+ Wine/Black), OffroadHatchback (+ Blue/White),
// Hatchback_02 (+ Black/Blue), Sedan_02 (+ Grey/Red), Offroad_02,
// Truck_01_Covered (+ Blue/Orange), Truck_01_Cargo (+ Blue/Grey/Orange).
//
// Что настраивается (все числа - в class SimulationModule):
// - Разгон/мощность двигателя - class Engine (torqueCurve, обороты).
// - Передачи - class Gearbox (ratios[] - передаточные числа, reverse).
// - Сцепление - class Clutch.
// - Тормоза - class Brake.
// - "Зацеп" с дорогой - косвенно через class Axles > Front/Rear/Middle >
//   Differential (передаточное число дифференциала) и Suspension
//   (жёсткость/демпфер подвески) - отдельного параметра трения шин
//   в ванильном конфиге нет, зацеп определяется этими значениями.
// - Расход и объём топливного бака - fuelCapacity/fuelConsumption.
//
// Требует DZ_Vehicles_Wheeled (часть игры, идёт с сервером по
// умолчанию - отдельно ставить не нужно).
// ============================================================

class CfgPatches
{
	class DZ_Vehicles_FIX
	{
		units[] = {"CivilianSedan_FIX","CivilianSedan_Wine_FIX","CivilianSedan_Black_FIX","OffroadHatchback_FIX","OffroadHatchback_Blue_FIX","OffroadHatchback_White_FIX","Hatchback_02_FIX","Hatchback_02_Black_FIX","Hatchback_02_Blue_FIX","Sedan_02_FIX","Sedan_02_Grey_FIX","Sedan_02_Red_FIX","Offroad_02_FIX","Truck_01_Covered_FIX","Truck_01_Covered_Blue_FIX","Truck_01_Covered_Orange_FIX","Truck_01_Cargo_FIX","Truck_01_Cargo_Blue_FIX","Truck_01_Cargo_Grey_FIX","Truck_01_Cargo_Orange_FIX"};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"DZ_Vehicles_Wheeled"};
	};
};

class CfgVehicles
{
	class CivilianSedan;
	class CivilianSedan_Wine;
	class CivilianSedan_Black;
	class OffroadHatchback;
	class OffroadHatchback_Blue;
	class OffroadHatchback_White;
	class Hatchback_02;
	class Hatchback_02_Black;
	class Hatchback_02_Blue;
	class Sedan_02;
	class Sedan_02_Grey;
	class Sedan_02_Red;
	class Offroad_02;
	class Truck_01_Covered;
	class Truck_01_Covered_Blue;
	class Truck_01_Covered_Orange;
	class Truck_01_Cargo;
	class Truck_01_Cargo_Blue;
	class Truck_01_Cargo_Grey;
	class Truck_01_Cargo_Orange;

	class CivilianSedan_FIX : CivilianSedan
	{
		fuelCapacity = 55;
		fuelConsumption = 13;
		class SimulationModule
		{
			class Steering
			{
				maxSteeringAngle = 35;
				increaseSpeed[] = {0,50,10,40,30,30,60,15,100,7,120,4};
				decreaseSpeed[] = {0,90,60,60,120,40};
				centeringSpeed[] = {0,0,15,30,60,60,100,80};
			};
			class Throttle
			{
				reactionTime = 0.35;
				defaultThrust = 0.65;
				gentleThrust = 0.55;
				turboCoef = 6.0;
				gentleCoef = 0.7;
			};
			class Brake
			{
				pressureBySpeed[] = {0,0.43,10,0.38,20,0.35,40,0.25,50,0.27,80,0.29,100,0.31,140,0.38};
				gentleCoef = 0.6;
				minPressure = 0.2;
				reactionTime = 0.25;
				driverless = 0.1;
			};
			class Aerodynamics
			{
				frontalArea = 2.2;
				dragCoefficient = 0.45;
				downforceCoefficient = 0.8;
				downforceOffset[] = {0,0.4,-2.2};
			};
			drive = "DRIVE_RWD";
			class Engine
			{
				torqueCurve[] = {400,0,1000,157,1700,183,2500,187,4500,147,6000,0};
				inertia = 0.45;
				frictionTorque = 130;
				rollingFriction = 1.5;
				viscousFriction = 0.5;
				rpmIdle = 900;
				rpmMin = 1000;
				rpmClutch = 1250;
				rpmRedline = 4700;
			};
			class Clutch
			{
				maxTorqueTransfer = 400;
				uncoupleTime = 0.3;
				coupleTime = 0.3;
			};
			class Gearbox
			{
				type = "GEARBOX_MANUAL";
				reverse = 3.51;
				ratios[] = {3.5,2.26,1.45,1.0};
			};
			class Axles
			{
				class Front
				{
					maxBrakeTorque = 2100;
					wheelHubMass = 10;
					wheelHubRadius = 0.15;
					class Suspension
					{
						stiffness = 60000;
						compression = 2100;
						damping = 5500;
						travelMaxUp = 0.079;
						travelMaxDown = 0.06;
					};
				};
				class Rear
				{
					maxBrakeTorque = 2200;
					maxHandbrakeTorque = 4400;
					wheelHubMass = 10;
					wheelHubRadius = 0.15;
					class Differential
					{
						ratio = 4.1;
						type = "DIFFERENTIAL_OPEN";
					};
					class Suspension
					{
						stiffness = 34000;
						compression = 2000;
						damping = 5100;
						travelMaxUp = 0.086;
						travelMaxDown = 0.133;
					};
				};
			};
		};
	};

	class CivilianSedan_Wine_FIX : CivilianSedan_Wine
	{
		fuelCapacity = 55;
		fuelConsumption = 13;
		class SimulationModule
		{
			class Steering
			{
				maxSteeringAngle = 35;
				increaseSpeed[] = {0,50,10,40,30,30,60,15,100,7,120,4};
				decreaseSpeed[] = {0,90,60,60,120,40};
				centeringSpeed[] = {0,0,15,30,60,60,100,80};
			};
			class Throttle
			{
				reactionTime = 0.35;
				defaultThrust = 0.65;
				gentleThrust = 0.55;
				turboCoef = 6.0;
				gentleCoef = 0.7;
			};
			class Brake
			{
				pressureBySpeed[] = {0,0.43,10,0.38,20,0.35,40,0.25,50,0.27,80,0.29,100,0.31,140,0.38};
				gentleCoef = 0.6;
				minPressure = 0.2;
				reactionTime = 0.25;
				driverless = 0.1;
			};
			class Aerodynamics
			{
				frontalArea = 2.2;
				dragCoefficient = 0.45;
				downforceCoefficient = 0.8;
				downforceOffset[] = {0,0.4,-2.2};
			};
			drive = "DRIVE_RWD";
			class Engine
			{
				torqueCurve[] = {400,0,1000,157,1700,183,2500,187,4500,147,6000,0};
				inertia = 0.45;
				frictionTorque = 130;
				rollingFriction = 1.5;
				viscousFriction = 0.5;
				rpmIdle = 900;
				rpmMin = 1000;
				rpmClutch = 1250;
				rpmRedline = 4700;
			};
			class Clutch
			{
				maxTorqueTransfer = 400;
				uncoupleTime = 0.3;
				coupleTime = 0.3;
			};
			class Gearbox
			{
				type = "GEARBOX_MANUAL";
				reverse = 3.51;
				ratios[] = {3.5,2.26,1.45,1.0};
			};
			class Axles
			{
				class Front
				{
					maxBrakeTorque = 2100;
					wheelHubMass = 10;
					wheelHubRadius = 0.15;
					class Suspension
					{
						stiffness = 60000;
						compression = 2100;
						damping = 5500;
						travelMaxUp = 0.079;
						travelMaxDown = 0.06;
					};
				};
				class Rear
				{
					maxBrakeTorque = 2200;
					maxHandbrakeTorque = 4400;
					wheelHubMass = 10;
					wheelHubRadius = 0.15;
					class Differential
					{
						ratio = 4.1;
						type = "DIFFERENTIAL_OPEN";
					};
					class Suspension
					{
						stiffness = 34000;
						compression = 2000;
						damping = 5100;
						travelMaxUp = 0.086;
						travelMaxDown = 0.133;
					};
				};
			};
		};
	};

	class CivilianSedan_Black_FIX : CivilianSedan_Black
	{
		fuelCapacity = 55;
		fuelConsumption = 13;
		class SimulationModule
		{
			class Steering
			{
				maxSteeringAngle = 35;
				increaseSpeed[] = {0,50,10,40,30,30,60,15,100,7,120,4};
				decreaseSpeed[] = {0,90,60,60,120,40};
				centeringSpeed[] = {0,0,15,30,60,60,100,80};
			};
			class Throttle
			{
				reactionTime = 0.35;
				defaultThrust = 0.65;
				gentleThrust = 0.55;
				turboCoef = 6.0;
				gentleCoef = 0.7;
			};
			class Brake
			{
				pressureBySpeed[] = {0,0.43,10,0.38,20,0.35,40,0.25,50,0.27,80,0.29,100,0.31,140,0.38};
				gentleCoef = 0.6;
				minPressure = 0.2;
				reactionTime = 0.25;
				driverless = 0.1;
			};
			class Aerodynamics
			{
				frontalArea = 2.2;
				dragCoefficient = 0.45;
				downforceCoefficient = 0.8;
				downforceOffset[] = {0,0.4,-2.2};
			};
			drive = "DRIVE_RWD";
			class Engine
			{
				torqueCurve[] = {400,0,1000,157,1700,183,2500,187,4500,147,6000,0};
				inertia = 0.45;
				frictionTorque = 130;
				rollingFriction = 1.5;
				viscousFriction = 0.5;
				rpmIdle = 900;
				rpmMin = 1000;
				rpmClutch = 1250;
				rpmRedline = 4700;
			};
			class Clutch
			{
				maxTorqueTransfer = 400;
				uncoupleTime = 0.3;
				coupleTime = 0.3;
			};
			class Gearbox
			{
				type = "GEARBOX_MANUAL";
				reverse = 3.51;
				ratios[] = {3.5,2.26,1.45,1.0};
			};
			class Axles
			{
				class Front
				{
					maxBrakeTorque = 2100;
					wheelHubMass = 10;
					wheelHubRadius = 0.15;
					class Suspension
					{
						stiffness = 60000;
						compression = 2100;
						damping = 5500;
						travelMaxUp = 0.079;
						travelMaxDown = 0.06;
					};
				};
				class Rear
				{
					maxBrakeTorque = 2200;
					maxHandbrakeTorque = 4400;
					wheelHubMass = 10;
					wheelHubRadius = 0.15;
					class Differential
					{
						ratio = 4.1;
						type = "DIFFERENTIAL_OPEN";
					};
					class Suspension
					{
						stiffness = 34000;
						compression = 2000;
						damping = 5100;
						travelMaxUp = 0.086;
						travelMaxDown = 0.133;
					};
				};
			};
		};
	};

	class OffroadHatchback_FIX : OffroadHatchback
	{
		fuelCapacity = 42;
		fuelConsumption = 11;
		class SimulationModule
		{
			class Steering
			{
				maxSteeringAngle = 30;
				increaseSpeed[] = {0,40,30,20,100,5};
				decreaseSpeed[] = {0,80,60,40,90,20};
				centeringSpeed[] = {0,0,15,25,60,40,100,60};
			};
			class Throttle
			{
				reactionTime = 0.9;
				defaultThrust = 0.85;
				gentleThrust = 0.7;
				turboCoef = 4.0;
				gentleCoef = 0.75;
			};
			class Brake
			{
				pressureBySpeed[] = {0,0.75,10,0.65,20,0.5,40,0.4,60,0.43,80,0.45,100,0.5,120,0.65};
				gentleCoef = 0.65;
				minPressure = 0.2;
				reactionTime = 0.3;
				driverless = 0.1;
			};
			class Aerodynamics
			{
				frontalArea = 2.18;
				dragCoefficient = 0.56;
			};
			drive = "DRIVE_AWD";
			class Engine
			{
				torqueCurve[] = {650,0,750,40,1400,80,3400,114,5400,95,8000,0};
				inertia = 0.11;
				frictionTorque = 100;
				rollingFriction = 0.5;
				viscousFriction = 0.5;
				rpmIdle = 800;
				rpmMin = 900;
				rpmClutch = 1400;
				rpmRedline = 6000;
			};
			class Clutch
			{
				maxTorqueTransfer = 240;
				uncoupleTime = 0.3;
				coupleTime = 0.45;
			};
			class Gearbox
			{
				type = "GEARBOX_MANUAL";
				reverse = 3.526;
				ratios[] = {3.667,2.1,1.361,1.0};
			};
			class CentralDifferential
			{
				ratio = 1.5;
				type = "DIFFERENTIAL_LOCKED";
			};
			class Axles
			{
				class Front
				{
					maxBrakeTorque = 1900;
					maxHandbrakeTorque = 5000;
					wheelHubMass = 5;
					wheelHubRadius = 0.15;
					class Differential
					{
						ratio = 4.1;
						type = "DIFFERENTIAL_OPEN";
					};
					class Suspension
					{
						stiffness = 40000;
						compression = 2100;
						damping = 7500;
						travelMaxUp = 0.0882;
						travelMaxDown = 0.0833;
					};
				};
				class Rear
				{
					maxBrakeTorque = 1560;
					maxHandbrakeTorque = 5000;
					wheelHubMass = 5;
					wheelHubRadius = 0.15;
					class Differential
					{
						ratio = 4.1;
						type = "DIFFERENTIAL_OPEN";
					};
					class Suspension
					{
						stiffness = 40000;
						compression = 2200;
						damping = 7600;
						travelMaxUp = 0.1587;
						travelMaxDown = 0.1059;
					};
				};
			};
		};
	};

	class OffroadHatchback_Blue_FIX : OffroadHatchback_Blue
	{
		fuelCapacity = 42;
		fuelConsumption = 11;
		class SimulationModule
		{
			class Steering
			{
				maxSteeringAngle = 30;
				increaseSpeed[] = {0,40,30,20,100,5};
				decreaseSpeed[] = {0,80,60,40,90,20};
				centeringSpeed[] = {0,0,15,25,60,40,100,60};
			};
			class Throttle
			{
				reactionTime = 0.9;
				defaultThrust = 0.85;
				gentleThrust = 0.7;
				turboCoef = 4.0;
				gentleCoef = 0.75;
			};
			class Brake
			{
				pressureBySpeed[] = {0,0.75,10,0.65,20,0.5,40,0.4,60,0.43,80,0.45,100,0.5,120,0.65};
				gentleCoef = 0.65;
				minPressure = 0.2;
				reactionTime = 0.3;
				driverless = 0.1;
			};
			class Aerodynamics
			{
				frontalArea = 2.18;
				dragCoefficient = 0.56;
			};
			drive = "DRIVE_AWD";
			class Engine
			{
				torqueCurve[] = {650,0,750,40,1400,80,3400,114,5400,95,8000,0};
				inertia = 0.11;
				frictionTorque = 100;
				rollingFriction = 0.5;
				viscousFriction = 0.5;
				rpmIdle = 800;
				rpmMin = 900;
				rpmClutch = 1400;
				rpmRedline = 6000;
			};
			class Clutch
			{
				maxTorqueTransfer = 240;
				uncoupleTime = 0.3;
				coupleTime = 0.45;
			};
			class Gearbox
			{
				type = "GEARBOX_MANUAL";
				reverse = 3.526;
				ratios[] = {3.667,2.1,1.361,1.0};
			};
			class CentralDifferential
			{
				ratio = 1.5;
				type = "DIFFERENTIAL_LOCKED";
			};
			class Axles
			{
				class Front
				{
					maxBrakeTorque = 1900;
					maxHandbrakeTorque = 5000;
					wheelHubMass = 5;
					wheelHubRadius = 0.15;
					class Differential
					{
						ratio = 4.1;
						type = "DIFFERENTIAL_OPEN";
					};
					class Suspension
					{
						stiffness = 40000;
						compression = 2100;
						damping = 7500;
						travelMaxUp = 0.0882;
						travelMaxDown = 0.0833;
					};
				};
				class Rear
				{
					maxBrakeTorque = 1560;
					maxHandbrakeTorque = 5000;
					wheelHubMass = 5;
					wheelHubRadius = 0.15;
					class Differential
					{
						ratio = 4.1;
						type = "DIFFERENTIAL_OPEN";
					};
					class Suspension
					{
						stiffness = 40000;
						compression = 2200;
						damping = 7600;
						travelMaxUp = 0.1587;
						travelMaxDown = 0.1059;
					};
				};
			};
		};
	};

	class OffroadHatchback_White_FIX : OffroadHatchback_White
	{
		fuelCapacity = 42;
		fuelConsumption = 11;
		class SimulationModule
		{
			class Steering
			{
				maxSteeringAngle = 30;
				increaseSpeed[] = {0,40,30,20,100,5};
				decreaseSpeed[] = {0,80,60,40,90,20};
				centeringSpeed[] = {0,0,15,25,60,40,100,60};
			};
			class Throttle
			{
				reactionTime = 0.9;
				defaultThrust = 0.85;
				gentleThrust = 0.7;
				turboCoef = 4.0;
				gentleCoef = 0.75;
			};
			class Brake
			{
				pressureBySpeed[] = {0,0.75,10,0.65,20,0.5,40,0.4,60,0.43,80,0.45,100,0.5,120,0.65};
				gentleCoef = 0.65;
				minPressure = 0.2;
				reactionTime = 0.3;
				driverless = 0.1;
			};
			class Aerodynamics
			{
				frontalArea = 2.18;
				dragCoefficient = 0.56;
			};
			drive = "DRIVE_AWD";
			class Engine
			{
				torqueCurve[] = {650,0,750,40,1400,80,3400,114,5400,95,8000,0};
				inertia = 0.11;
				frictionTorque = 100;
				rollingFriction = 0.5;
				viscousFriction = 0.5;
				rpmIdle = 800;
				rpmMin = 900;
				rpmClutch = 1400;
				rpmRedline = 6000;
			};
			class Clutch
			{
				maxTorqueTransfer = 240;
				uncoupleTime = 0.3;
				coupleTime = 0.45;
			};
			class Gearbox
			{
				type = "GEARBOX_MANUAL";
				reverse = 3.526;
				ratios[] = {3.667,2.1,1.361,1.0};
			};
			class CentralDifferential
			{
				ratio = 1.5;
				type = "DIFFERENTIAL_LOCKED";
			};
			class Axles
			{
				class Front
				{
					maxBrakeTorque = 1900;
					maxHandbrakeTorque = 5000;
					wheelHubMass = 5;
					wheelHubRadius = 0.15;
					class Differential
					{
						ratio = 4.1;
						type = "DIFFERENTIAL_OPEN";
					};
					class Suspension
					{
						stiffness = 40000;
						compression = 2100;
						damping = 7500;
						travelMaxUp = 0.0882;
						travelMaxDown = 0.0833;
					};
				};
				class Rear
				{
					maxBrakeTorque = 1560;
					maxHandbrakeTorque = 5000;
					wheelHubMass = 5;
					wheelHubRadius = 0.15;
					class Differential
					{
						ratio = 4.1;
						type = "DIFFERENTIAL_OPEN";
					};
					class Suspension
					{
						stiffness = 40000;
						compression = 2200;
						damping = 7600;
						travelMaxUp = 0.1587;
						travelMaxDown = 0.1059;
					};
				};
			};
		};
	};

	class Hatchback_02_FIX : Hatchback_02
	{
		fuelCapacity = 55;
		fuelConsumption = 6.5;
		class SimulationModule
		{
			class Steering
			{
				maxSteeringAngle = 35;
				increaseSpeed[] = {0,50,60,30,100,15};
				decreaseSpeed[] = {0,90,60,45,100,20};
				centeringSpeed[] = {0,0,15,27,60,45,100,63};
			};
			class Throttle
			{
				reactionTime = 0.85;
				defaultThrust = 0.7;
				gentleThrust = 0.4;
				turboCoef = 2.2;
				gentleCoef = 0.5;
			};
			class Brake
			{
				pressureBySpeed[] = {0,0.5,10,0.4,20,0.3,40,0.28,60,0.3,80,0.38,100,0.42,120,0.48,150,0.6};
				gentleCoef = 0.7;
				minPressure = 0.2;
				reactionTime = 0.2;
				driverless = 0.1;
			};
			class Aerodynamics
			{
				frontalArea = 2.15;
				dragCoefficient = 0.52;
				downforceCoefficient = 0.01;
				downforceOffset[] = {0,0.8,-0.7};
			};
			drive = "DRIVE_FWD";
			class Engine
			{
				torqueCurve[] = {850,0,1150,90,2000,130,4400,186,5800,165,7500,0};
				inertia = 0.21;
				frictionTorque = 150;
				rollingFriction = 0.2;
				viscousFriction = 0.5;
				rpmIdle = 1250;
				rpmMin = 1500;
				rpmClutch = 2000;
				rpmRedline = 6250;
			};
			class Clutch
			{
				maxTorqueTransfer = 360;
				uncoupleTime = 0.25;
				coupleTime = 0.35;
			};
			class Gearbox
			{
				type = "GEARBOX_MANUAL";
				reverse = 3.167;
				ratios[] = {3.455,2.118,1.444,1.129,0.912};
			};
			class Axles
			{
				class Front
				{
					maxBrakeTorque = 2060;
					wheelHubMass = 5;
					wheelHubRadius = 0.125;
					class Differential
					{
						ratio = 3.667;
						type = "DIFFERENTIAL_OPEN";
					};
					class Suspension
					{
						stiffness = 27000;
						compression = 2000;
						damping = 7500;
						travelMaxUp = 0.16;
						travelMaxDown = 0.16;
					};
				};
				class Rear
				{
					maxBrakeTorque = 1500;
					maxHandbrakeTorque = 4000;
					wheelHubMass = 5;
					wheelHubRadius = 0.125;
					class Suspension
					{
						stiffness = 27500;
						compression = 2100;
						damping = 8000;
						travelMaxUp = 0.16;
						travelMaxDown = 0.16;
					};
				};
			};
		};
	};

	class Hatchback_02_Black_FIX : Hatchback_02_Black
	{
		fuelCapacity = 55;
		fuelConsumption = 6.5;
		class SimulationModule
		{
			class Steering
			{
				maxSteeringAngle = 35;
				increaseSpeed[] = {0,50,60,30,100,15};
				decreaseSpeed[] = {0,90,60,45,100,20};
				centeringSpeed[] = {0,0,15,27,60,45,100,63};
			};
			class Throttle
			{
				reactionTime = 0.85;
				defaultThrust = 0.7;
				gentleThrust = 0.4;
				turboCoef = 2.2;
				gentleCoef = 0.5;
			};
			class Brake
			{
				pressureBySpeed[] = {0,0.5,10,0.4,20,0.3,40,0.28,60,0.3,80,0.38,100,0.42,120,0.48,150,0.6};
				gentleCoef = 0.7;
				minPressure = 0.2;
				reactionTime = 0.2;
				driverless = 0.1;
			};
			class Aerodynamics
			{
				frontalArea = 2.15;
				dragCoefficient = 0.52;
				downforceCoefficient = 0.01;
				downforceOffset[] = {0,0.8,-0.7};
			};
			drive = "DRIVE_FWD";
			class Engine
			{
				torqueCurve[] = {850,0,1150,90,2000,130,4400,186,5800,165,7500,0};
				inertia = 0.21;
				frictionTorque = 150;
				rollingFriction = 0.2;
				viscousFriction = 0.5;
				rpmIdle = 1250;
				rpmMin = 1500;
				rpmClutch = 2000;
				rpmRedline = 6250;
			};
			class Clutch
			{
				maxTorqueTransfer = 360;
				uncoupleTime = 0.25;
				coupleTime = 0.35;
			};
			class Gearbox
			{
				type = "GEARBOX_MANUAL";
				reverse = 3.167;
				ratios[] = {3.455,2.118,1.444,1.129,0.912};
			};
			class Axles
			{
				class Front
				{
					maxBrakeTorque = 2060;
					wheelHubMass = 5;
					wheelHubRadius = 0.125;
					class Differential
					{
						ratio = 3.667;
						type = "DIFFERENTIAL_OPEN";
					};
					class Suspension
					{
						stiffness = 27000;
						compression = 2000;
						damping = 7500;
						travelMaxUp = 0.16;
						travelMaxDown = 0.16;
					};
				};
				class Rear
				{
					maxBrakeTorque = 1500;
					maxHandbrakeTorque = 4000;
					wheelHubMass = 5;
					wheelHubRadius = 0.125;
					class Suspension
					{
						stiffness = 27500;
						compression = 2100;
						damping = 8000;
						travelMaxUp = 0.16;
						travelMaxDown = 0.16;
					};
				};
			};
		};
	};

	class Hatchback_02_Blue_FIX : Hatchback_02_Blue
	{
		fuelCapacity = 55;
		fuelConsumption = 6.5;
		class SimulationModule
		{
			class Steering
			{
				maxSteeringAngle = 35;
				increaseSpeed[] = {0,50,60,30,100,15};
				decreaseSpeed[] = {0,90,60,45,100,20};
				centeringSpeed[] = {0,0,15,27,60,45,100,63};
			};
			class Throttle
			{
				reactionTime = 0.85;
				defaultThrust = 0.7;
				gentleThrust = 0.4;
				turboCoef = 2.2;
				gentleCoef = 0.5;
			};
			class Brake
			{
				pressureBySpeed[] = {0,0.5,10,0.4,20,0.3,40,0.28,60,0.3,80,0.38,100,0.42,120,0.48,150,0.6};
				gentleCoef = 0.7;
				minPressure = 0.2;
				reactionTime = 0.2;
				driverless = 0.1;
			};
			class Aerodynamics
			{
				frontalArea = 2.15;
				dragCoefficient = 0.52;
				downforceCoefficient = 0.01;
				downforceOffset[] = {0,0.8,-0.7};
			};
			drive = "DRIVE_FWD";
			class Engine
			{
				torqueCurve[] = {850,0,1150,90,2000,130,4400,186,5800,165,7500,0};
				inertia = 0.21;
				frictionTorque = 150;
				rollingFriction = 0.2;
				viscousFriction = 0.5;
				rpmIdle = 1250;
				rpmMin = 1500;
				rpmClutch = 2000;
				rpmRedline = 6250;
			};
			class Clutch
			{
				maxTorqueTransfer = 360;
				uncoupleTime = 0.25;
				coupleTime = 0.35;
			};
			class Gearbox
			{
				type = "GEARBOX_MANUAL";
				reverse = 3.167;
				ratios[] = {3.455,2.118,1.444,1.129,0.912};
			};
			class Axles
			{
				class Front
				{
					maxBrakeTorque = 2060;
					wheelHubMass = 5;
					wheelHubRadius = 0.125;
					class Differential
					{
						ratio = 3.667;
						type = "DIFFERENTIAL_OPEN";
					};
					class Suspension
					{
						stiffness = 27000;
						compression = 2000;
						damping = 7500;
						travelMaxUp = 0.16;
						travelMaxDown = 0.16;
					};
				};
				class Rear
				{
					maxBrakeTorque = 1500;
					maxHandbrakeTorque = 4000;
					wheelHubMass = 5;
					wheelHubRadius = 0.125;
					class Suspension
					{
						stiffness = 27500;
						compression = 2100;
						damping = 8000;
						travelMaxUp = 0.16;
						travelMaxDown = 0.16;
					};
				};
			};
		};
	};

	class Sedan_02_FIX : Sedan_02
	{
		fuelCapacity = 38;
		fuelConsumption = 7;
		class SimulationModule
		{
			class Steering
			{
				maxSteeringAngle = 30;
				increaseSpeed[] = {0,40,30,20,60,10,100,5};
				decreaseSpeed[] = {0,90,60,70,100,50};
				centeringSpeed[] = {0,0,15,35,60,65,100,90};
			};
			class Throttle
			{
				reactionTime = 0.8;
				defaultThrust = 0.75;
				gentleThrust = 0.5;
				turboCoef = 3.8;
				gentleCoef = 0.5;
			};
			class Brake
			{
				pressureBySpeed[] = {0,0.85,10,0.75,20,0.45,40,0.35,80,0.4,100,0.45,120,0.65};
				gentleCoef = 0.7;
				minPressure = 0.3;
				reactionTime = 0.35;
				driverless = 0.1;
			};
			class Aerodynamics
			{
				frontalArea = 2.0;
				dragCoefficient = 0.35;
			};
			drive = "DRIVE_RWD";
			class Engine
			{
				torqueCurve[] = {600,0,990,50,1800,75,3000,82,5000,71,7000,0};
				inertia = 0.2;
				frictionTorque = 80;
				rollingFriction = 0.5;
				viscousFriction = 0;
				rpmIdle = 900;
				rpmMin = 1000;
				rpmClutch = 1500;
				rpmRedline = 5750;
			};
			class Clutch
			{
				maxTorqueTransfer = 165;
				uncoupleTime = 0.1;
				coupleTime = 0.3;
			};
			class Gearbox
			{
				type = "GEARBOX_MANUAL";
				reverse = 3.27;
				ratios[] = {3.8,2.12,1.41,0.96};
			};
			class Axles
			{
				class Front
				{
					maxBrakeTorque = 1220;
					wheelHubMass = 5;
					wheelHubRadius = 0.17;
					class Suspension
					{
						stiffness = 25000;
						compression = 1600;
						damping = 5200;
						travelMaxUp = 0.07;
						travelMaxDown = 0.08;
					};
				};
				class Rear
				{
					maxBrakeTorque = 1040;
					maxHandbrakeTorque = 2400;
					wheelHubMass = 5;
					wheelHubRadius = 0.17;
					class Differential
					{
						ratio = 4.22;
						type = "DIFFERENTIAL_OPEN";
					};
					class Suspension
					{
						stiffness = 21500;
						compression = 1800;
						damping = 5600;
						travelMaxUp = 0.1;
						travelMaxDown = 0.1;
					};
				};
			};
		};
	};

	class Sedan_02_Grey_FIX : Sedan_02_Grey
	{
		fuelCapacity = 38;
		fuelConsumption = 7;
		class SimulationModule
		{
			class Steering
			{
				maxSteeringAngle = 30;
				increaseSpeed[] = {0,40,30,20,60,10,100,5};
				decreaseSpeed[] = {0,90,60,70,100,50};
				centeringSpeed[] = {0,0,15,35,60,65,100,90};
			};
			class Throttle
			{
				reactionTime = 0.8;
				defaultThrust = 0.75;
				gentleThrust = 0.5;
				turboCoef = 3.8;
				gentleCoef = 0.5;
			};
			class Brake
			{
				pressureBySpeed[] = {0,0.85,10,0.75,20,0.45,40,0.35,80,0.4,100,0.45,120,0.65};
				gentleCoef = 0.7;
				minPressure = 0.3;
				reactionTime = 0.35;
				driverless = 0.1;
			};
			class Aerodynamics
			{
				frontalArea = 2.0;
				dragCoefficient = 0.35;
			};
			drive = "DRIVE_RWD";
			class Engine
			{
				torqueCurve[] = {600,0,990,50,1800,75,3000,82,5000,71,7000,0};
				inertia = 0.2;
				frictionTorque = 80;
				rollingFriction = 0.5;
				viscousFriction = 0;
				rpmIdle = 900;
				rpmMin = 1000;
				rpmClutch = 1500;
				rpmRedline = 5750;
			};
			class Clutch
			{
				maxTorqueTransfer = 165;
				uncoupleTime = 0.1;
				coupleTime = 0.3;
			};
			class Gearbox
			{
				type = "GEARBOX_MANUAL";
				reverse = 3.27;
				ratios[] = {3.8,2.12,1.41,0.96};
			};
			class Axles
			{
				class Front
				{
					maxBrakeTorque = 1220;
					wheelHubMass = 5;
					wheelHubRadius = 0.17;
					class Suspension
					{
						stiffness = 25000;
						compression = 1600;
						damping = 5200;
						travelMaxUp = 0.07;
						travelMaxDown = 0.08;
					};
				};
				class Rear
				{
					maxBrakeTorque = 1040;
					maxHandbrakeTorque = 2400;
					wheelHubMass = 5;
					wheelHubRadius = 0.17;
					class Differential
					{
						ratio = 4.22;
						type = "DIFFERENTIAL_OPEN";
					};
					class Suspension
					{
						stiffness = 21500;
						compression = 1800;
						damping = 5600;
						travelMaxUp = 0.1;
						travelMaxDown = 0.1;
					};
				};
			};
		};
	};

	class Sedan_02_Red_FIX : Sedan_02_Red
	{
		fuelCapacity = 38;
		fuelConsumption = 7;
		class SimulationModule
		{
			class Steering
			{
				maxSteeringAngle = 30;
				increaseSpeed[] = {0,40,30,20,60,10,100,5};
				decreaseSpeed[] = {0,90,60,70,100,50};
				centeringSpeed[] = {0,0,15,35,60,65,100,90};
			};
			class Throttle
			{
				reactionTime = 0.8;
				defaultThrust = 0.75;
				gentleThrust = 0.5;
				turboCoef = 3.8;
				gentleCoef = 0.5;
			};
			class Brake
			{
				pressureBySpeed[] = {0,0.85,10,0.75,20,0.45,40,0.35,80,0.4,100,0.45,120,0.65};
				gentleCoef = 0.7;
				minPressure = 0.3;
				reactionTime = 0.35;
				driverless = 0.1;
			};
			class Aerodynamics
			{
				frontalArea = 2.0;
				dragCoefficient = 0.35;
			};
			drive = "DRIVE_RWD";
			class Engine
			{
				torqueCurve[] = {600,0,990,50,1800,75,3000,82,5000,71,7000,0};
				inertia = 0.2;
				frictionTorque = 80;
				rollingFriction = 0.5;
				viscousFriction = 0;
				rpmIdle = 900;
				rpmMin = 1000;
				rpmClutch = 1500;
				rpmRedline = 5750;
			};
			class Clutch
			{
				maxTorqueTransfer = 165;
				uncoupleTime = 0.1;
				coupleTime = 0.3;
			};
			class Gearbox
			{
				type = "GEARBOX_MANUAL";
				reverse = 3.27;
				ratios[] = {3.8,2.12,1.41,0.96};
			};
			class Axles
			{
				class Front
				{
					maxBrakeTorque = 1220;
					wheelHubMass = 5;
					wheelHubRadius = 0.17;
					class Suspension
					{
						stiffness = 25000;
						compression = 1600;
						damping = 5200;
						travelMaxUp = 0.07;
						travelMaxDown = 0.08;
					};
				};
				class Rear
				{
					maxBrakeTorque = 1040;
					maxHandbrakeTorque = 2400;
					wheelHubMass = 5;
					wheelHubRadius = 0.17;
					class Differential
					{
						ratio = 4.22;
						type = "DIFFERENTIAL_OPEN";
					};
					class Suspension
					{
						stiffness = 21500;
						compression = 1800;
						damping = 5600;
						travelMaxUp = 0.1;
						travelMaxDown = 0.1;
					};
				};
			};
		};
	};

	class Offroad_02_FIX : Offroad_02
	{
		fuelCapacity = 115;
		fuelConsumption = 30;
		class SimulationModule
		{
			class Steering
			{
				maxSteeringAngle = 30;
				increaseSpeed[] = {0,40,30,20,100,10};
				decreaseSpeed[] = {0,80,60,40,90,20};
				centeringSpeed[] = {0,0,15,25,60,40,100,60};
			};
			class Throttle
			{
				reactionTime = 1.0;
				defaultThrust = 0.85;
				gentleThrust = 0.7;
				turboCoef = 4.0;
				gentleCoef = 0.75;
			};
			class Brake
			{
				pressureBySpeed[] = {0,0.85,10,0.75,20,0.65,50,0.45,80,0.6,100,0.75};
				gentleCoef = 0.7;
				minPressure = 0.2;
				reactionTime = 0.15;
				driverless = 0.1;
			};
			class Aerodynamics
			{
				frontalArea = 3.05;
				dragCoefficient = 0.58;
			};
			drive = "DRIVE_AWD";
			class Engine
			{
				torqueCurve[] = {525,0,1000,200,1300,313,2500,384,3600,316,5120,0};
				inertia = 0.2;
				frictionTorque = 90;
				rollingFriction = 0.7;
				viscousFriction = 1.0;
				rpmIdle = 625;
				rpmMin = 800;
				rpmClutch = 1600;
				rpmRedline = 3700;
			};
			class Clutch
			{
				maxTorqueTransfer = 650;
				uncoupleTime = 0.2;
				coupleTime = 0.1;
			};
			class Gearbox
			{
				type = "GEARBOX_AUTOMATIC";
				reverse = 2.08;
				ratios[] = {2.48,1.48,1.0,0.75};
			};
			class CentralDifferential
			{
				ratio = 2.121;
				type = "DIFFERENTIAL_LOCKED";
			};
			class Axles
			{
				class Front
				{
					maxBrakeTorque = 4700;
					maxHandbrakeTorque = 10000;
					wheelHubMass = 20;
					wheelHubRadius = 0.15;
					class Differential
					{
						ratio = 2.73;
						type = "DIFFERENTIAL_LOCKED";
					};
					class Suspension
					{
						stiffness = 50000;
						compression = 3300;
						damping = 4100;
						travelMaxUp = 0.25;
						travelMaxDown = 0.25;
					};
				};
				class Rear
				{
					maxBrakeTorque = 4000;
					maxHandbrakeTorque = 10000;
					wheelHubMass = 20;
					wheelHubRadius = 0.15;
					class Differential
					{
						ratio = 2.73;
						type = "DIFFERENTIAL_LOCKED";
					};
					class Suspension
					{
						stiffness = 37500;
						compression = 3000;
						damping = 3600;
						travelMaxUp = 0.25;
						travelMaxDown = 0.25;
					};
				};
			};
		};
	};

	class Truck_01_Covered_FIX : Truck_01_Covered
	{
		fuelCapacity = 120;
		fuelConsumption = 30;
		class SimulationModule
		{
			class Steering
			{
				maxSteeringAngle = 35;
				increaseSpeed[] = {0,25,50,15};
				decreaseSpeed[] = {0,50,50,40};
				centeringSpeed[] = {0,25,50,15};
			};
			class Throttle
			{
				reactionTime = 0.2;
				defaultThrust = 0.8;
				gentleThrust = 0.6;
				turboCoef = 1.15;
				gentleCoef = 0.5;
			};
			class Brake
			{
				pressureBySpeed[] = {0,0.5,10,0.46,30,0.43,40,0.35,60,0.4,80,0.5};
				gentleCoef = 0.6;
				minPressure = 0.2;
				reactionTime = 0.3;
				driverless = 0.1;
			};
			class Aerodynamics
			{
				frontalArea = 5.75;
				dragCoefficient = 0.53;
			};
			drive = "DRIVE_642";
			class Engine
			{
				torqueCurve[] = {525,0,1000,330,1400,340,1900,300,2500,100,3000,0};
				inertia = 3.25;
				frictionTorque = 100;
				rollingFriction = 3;
				viscousFriction = 2.5;
				rpmIdle = 650;
				rpmMin = 750;
				rpmClutch = 850;
				rpmRedline = 2400;
			};
			class Clutch
			{
				maxTorqueTransfer = 720;
				uncoupleTime = 0.2;
				coupleTime = 0.65;
			};
			class Gearbox
			{
				type = "GEARBOX_MANUAL";
				reverse = 6.28;
				ratios[] = {6.19,3.13,1.75,1.0};
			};
			class CentralDifferential
			{
				ratio = 0.75;
				type = "DIFFERENTIAL_LOCKED";
			};
			class Axles
			{
				class Front
				{
					maxBrakeTorque = 9000;
					wheelHubMass = 25;
					wheelHubRadius = 0.3;
					class Suspension
					{
						stiffness = 65000;
						compression = 3000;
						damping = 7000;
						travelMaxUp = 0.14;
						travelMaxDown = 0.15;
					};
				};
				class Middle
				{
					maxBrakeTorque = 6200;
					maxHandbrakeTorque = 12000;
					wheelHubMass = 45;
					wheelHubRadius = 0.3;
					class Differential
					{
						ratio = 8.35;
						type = "DIFFERENTIAL_LOCKED";
					};
					class Suspension
					{
						stiffness = 55000;
						compression = 2500;
						damping = 8000;
						travelMaxUp = 0.095;
						travelMaxDown = 0.125;
					};
				};
				class Rear
				{
					maxBrakeTorque = 6200;
					maxHandbrakeTorque = 12000;
					wheelHubMass = 45;
					wheelHubRadius = 0.3;
					class Differential
					{
						ratio = 8.35;
						type = "DIFFERENTIAL_LOCKED";
					};
					class Suspension
					{
						stiffness = 55000;
						compression = 2500;
						damping = 8000;
						travelMaxUp = 0.095;
						travelMaxDown = 0.125;
					};
				};
			};
		};
	};

	class Truck_01_Covered_Blue_FIX : Truck_01_Covered_Blue
	{
		fuelCapacity = 120;
		fuelConsumption = 30;
		class SimulationModule
		{
			class Steering
			{
				maxSteeringAngle = 35;
				increaseSpeed[] = {0,25,50,15};
				decreaseSpeed[] = {0,50,50,40};
				centeringSpeed[] = {0,25,50,15};
			};
			class Throttle
			{
				reactionTime = 0.2;
				defaultThrust = 0.8;
				gentleThrust = 0.6;
				turboCoef = 1.15;
				gentleCoef = 0.5;
			};
			class Brake
			{
				pressureBySpeed[] = {0,0.5,10,0.46,30,0.43,40,0.35,60,0.4,80,0.5};
				gentleCoef = 0.6;
				minPressure = 0.2;
				reactionTime = 0.3;
				driverless = 0.1;
			};
			class Aerodynamics
			{
				frontalArea = 5.75;
				dragCoefficient = 0.53;
			};
			drive = "DRIVE_642";
			class Engine
			{
				torqueCurve[] = {525,0,1000,330,1400,340,1900,300,2500,100,3000,0};
				inertia = 3.25;
				frictionTorque = 100;
				rollingFriction = 3;
				viscousFriction = 2.5;
				rpmIdle = 650;
				rpmMin = 750;
				rpmClutch = 850;
				rpmRedline = 2400;
			};
			class Clutch
			{
				maxTorqueTransfer = 720;
				uncoupleTime = 0.2;
				coupleTime = 0.65;
			};
			class Gearbox
			{
				type = "GEARBOX_MANUAL";
				reverse = 6.28;
				ratios[] = {6.19,3.13,1.75,1.0};
			};
			class CentralDifferential
			{
				ratio = 0.75;
				type = "DIFFERENTIAL_LOCKED";
			};
			class Axles
			{
				class Front
				{
					maxBrakeTorque = 9000;
					wheelHubMass = 25;
					wheelHubRadius = 0.3;
					class Suspension
					{
						stiffness = 65000;
						compression = 3000;
						damping = 7000;
						travelMaxUp = 0.14;
						travelMaxDown = 0.15;
					};
				};
				class Middle
				{
					maxBrakeTorque = 6200;
					maxHandbrakeTorque = 12000;
					wheelHubMass = 45;
					wheelHubRadius = 0.3;
					class Differential
					{
						ratio = 8.35;
						type = "DIFFERENTIAL_LOCKED";
					};
					class Suspension
					{
						stiffness = 55000;
						compression = 2500;
						damping = 8000;
						travelMaxUp = 0.095;
						travelMaxDown = 0.125;
					};
				};
				class Rear
				{
					maxBrakeTorque = 6200;
					maxHandbrakeTorque = 12000;
					wheelHubMass = 45;
					wheelHubRadius = 0.3;
					class Differential
					{
						ratio = 8.35;
						type = "DIFFERENTIAL_LOCKED";
					};
					class Suspension
					{
						stiffness = 55000;
						compression = 2500;
						damping = 8000;
						travelMaxUp = 0.095;
						travelMaxDown = 0.125;
					};
				};
			};
		};
	};

	class Truck_01_Covered_Orange_FIX : Truck_01_Covered_Orange
	{
		fuelCapacity = 120;
		fuelConsumption = 30;
		class SimulationModule
		{
			class Steering
			{
				maxSteeringAngle = 35;
				increaseSpeed[] = {0,25,50,15};
				decreaseSpeed[] = {0,50,50,40};
				centeringSpeed[] = {0,25,50,15};
			};
			class Throttle
			{
				reactionTime = 0.2;
				defaultThrust = 0.8;
				gentleThrust = 0.6;
				turboCoef = 1.15;
				gentleCoef = 0.5;
			};
			class Brake
			{
				pressureBySpeed[] = {0,0.5,10,0.46,30,0.43,40,0.35,60,0.4,80,0.5};
				gentleCoef = 0.6;
				minPressure = 0.2;
				reactionTime = 0.3;
				driverless = 0.1;
			};
			class Aerodynamics
			{
				frontalArea = 5.75;
				dragCoefficient = 0.53;
			};
			drive = "DRIVE_642";
			class Engine
			{
				torqueCurve[] = {525,0,1000,330,1400,340,1900,300,2500,100,3000,0};
				inertia = 3.25;
				frictionTorque = 100;
				rollingFriction = 3;
				viscousFriction = 2.5;
				rpmIdle = 650;
				rpmMin = 750;
				rpmClutch = 850;
				rpmRedline = 2400;
			};
			class Clutch
			{
				maxTorqueTransfer = 720;
				uncoupleTime = 0.2;
				coupleTime = 0.65;
			};
			class Gearbox
			{
				type = "GEARBOX_MANUAL";
				reverse = 6.28;
				ratios[] = {6.19,3.13,1.75,1.0};
			};
			class CentralDifferential
			{
				ratio = 0.75;
				type = "DIFFERENTIAL_LOCKED";
			};
			class Axles
			{
				class Front
				{
					maxBrakeTorque = 9000;
					wheelHubMass = 25;
					wheelHubRadius = 0.3;
					class Suspension
					{
						stiffness = 65000;
						compression = 3000;
						damping = 7000;
						travelMaxUp = 0.14;
						travelMaxDown = 0.15;
					};
				};
				class Middle
				{
					maxBrakeTorque = 6200;
					maxHandbrakeTorque = 12000;
					wheelHubMass = 45;
					wheelHubRadius = 0.3;
					class Differential
					{
						ratio = 8.35;
						type = "DIFFERENTIAL_LOCKED";
					};
					class Suspension
					{
						stiffness = 55000;
						compression = 2500;
						damping = 8000;
						travelMaxUp = 0.095;
						travelMaxDown = 0.125;
					};
				};
				class Rear
				{
					maxBrakeTorque = 6200;
					maxHandbrakeTorque = 12000;
					wheelHubMass = 45;
					wheelHubRadius = 0.3;
					class Differential
					{
						ratio = 8.35;
						type = "DIFFERENTIAL_LOCKED";
					};
					class Suspension
					{
						stiffness = 55000;
						compression = 2500;
						damping = 8000;
						travelMaxUp = 0.095;
						travelMaxDown = 0.125;
					};
				};
			};
		};
	};

	class Truck_01_Cargo_FIX : Truck_01_Cargo
	{
		fuelCapacity = 120;
		fuelConsumption = 30;
		class SimulationModule
		{
			class Steering
			{
				maxSteeringAngle = 35;
				increaseSpeed[] = {0,25,50,15};
				decreaseSpeed[] = {0,50,50,40};
				centeringSpeed[] = {0,25,50,15};
			};
			class Throttle
			{
				reactionTime = 0.2;
				defaultThrust = 0.8;
				gentleThrust = 0.6;
				turboCoef = 1.15;
				gentleCoef = 0.5;
			};
			class Brake
			{
				pressureBySpeed[] = {0,0.5,10,0.46,30,0.43,40,0.35,60,0.4,80,0.5};
				gentleCoef = 0.6;
				minPressure = 0.2;
				reactionTime = 0.3;
				driverless = 0.1;
			};
			class Aerodynamics
			{
				frontalArea = 5.75;
				dragCoefficient = 0.53;
			};
			drive = "DRIVE_642";
			class Engine
			{
				torqueCurve[] = {525,0,1000,330,1400,340,1900,300,2500,100,3000,0};
				inertia = 3.25;
				frictionTorque = 100;
				rollingFriction = 3;
				viscousFriction = 2.5;
				rpmIdle = 650;
				rpmMin = 750;
				rpmClutch = 850;
				rpmRedline = 2400;
			};
			class Clutch
			{
				maxTorqueTransfer = 720;
				uncoupleTime = 0.2;
				coupleTime = 0.65;
			};
			class Gearbox
			{
				type = "GEARBOX_MANUAL";
				reverse = 6.28;
				ratios[] = {6.19,3.13,1.75,1.0};
			};
			class CentralDifferential
			{
				ratio = 0.75;
				type = "DIFFERENTIAL_LOCKED";
			};
			class Axles
			{
				class Front
				{
					maxBrakeTorque = 9000;
					wheelHubMass = 25;
					wheelHubRadius = 0.3;
					class Suspension
					{
						stiffness = 65000;
						compression = 3000;
						damping = 7000;
						travelMaxUp = 0.14;
						travelMaxDown = 0.15;
					};
				};
				class Middle
				{
					maxBrakeTorque = 6200;
					maxHandbrakeTorque = 12000;
					wheelHubMass = 45;
					wheelHubRadius = 0.3;
					class Differential
					{
						ratio = 8.35;
						type = "DIFFERENTIAL_LOCKED";
					};
					class Suspension
					{
						stiffness = 55000;
						compression = 2500;
						damping = 8000;
						travelMaxUp = 0.095;
						travelMaxDown = 0.125;
					};
				};
				class Rear
				{
					maxBrakeTorque = 6200;
					maxHandbrakeTorque = 12000;
					wheelHubMass = 45;
					wheelHubRadius = 0.3;
					class Differential
					{
						ratio = 8.35;
						type = "DIFFERENTIAL_LOCKED";
					};
					class Suspension
					{
						stiffness = 55000;
						compression = 2500;
						damping = 8000;
						travelMaxUp = 0.095;
						travelMaxDown = 0.125;
					};
				};
			};
		};
	};

	class Truck_01_Cargo_Blue_FIX : Truck_01_Cargo_Blue
	{
		fuelCapacity = 120;
		fuelConsumption = 30;
		class SimulationModule
		{
			class Steering
			{
				maxSteeringAngle = 35;
				increaseSpeed[] = {0,25,50,15};
				decreaseSpeed[] = {0,50,50,40};
				centeringSpeed[] = {0,25,50,15};
			};
			class Throttle
			{
				reactionTime = 0.2;
				defaultThrust = 0.8;
				gentleThrust = 0.6;
				turboCoef = 1.15;
				gentleCoef = 0.5;
			};
			class Brake
			{
				pressureBySpeed[] = {0,0.5,10,0.46,30,0.43,40,0.35,60,0.4,80,0.5};
				gentleCoef = 0.6;
				minPressure = 0.2;
				reactionTime = 0.3;
				driverless = 0.1;
			};
			class Aerodynamics
			{
				frontalArea = 5.75;
				dragCoefficient = 0.53;
			};
			drive = "DRIVE_642";
			class Engine
			{
				torqueCurve[] = {525,0,1000,330,1400,340,1900,300,2500,100,3000,0};
				inertia = 3.25;
				frictionTorque = 100;
				rollingFriction = 3;
				viscousFriction = 2.5;
				rpmIdle = 650;
				rpmMin = 750;
				rpmClutch = 850;
				rpmRedline = 2400;
			};
			class Clutch
			{
				maxTorqueTransfer = 720;
				uncoupleTime = 0.2;
				coupleTime = 0.65;
			};
			class Gearbox
			{
				type = "GEARBOX_MANUAL";
				reverse = 6.28;
				ratios[] = {6.19,3.13,1.75,1.0};
			};
			class CentralDifferential
			{
				ratio = 0.75;
				type = "DIFFERENTIAL_LOCKED";
			};
			class Axles
			{
				class Front
				{
					maxBrakeTorque = 9000;
					wheelHubMass = 25;
					wheelHubRadius = 0.3;
					class Suspension
					{
						stiffness = 65000;
						compression = 3000;
						damping = 7000;
						travelMaxUp = 0.14;
						travelMaxDown = 0.15;
					};
				};
				class Middle
				{
					maxBrakeTorque = 6200;
					maxHandbrakeTorque = 12000;
					wheelHubMass = 45;
					wheelHubRadius = 0.3;
					class Differential
					{
						ratio = 8.35;
						type = "DIFFERENTIAL_LOCKED";
					};
					class Suspension
					{
						stiffness = 55000;
						compression = 2500;
						damping = 8000;
						travelMaxUp = 0.095;
						travelMaxDown = 0.125;
					};
				};
				class Rear
				{
					maxBrakeTorque = 6200;
					maxHandbrakeTorque = 12000;
					wheelHubMass = 45;
					wheelHubRadius = 0.3;
					class Differential
					{
						ratio = 8.35;
						type = "DIFFERENTIAL_LOCKED";
					};
					class Suspension
					{
						stiffness = 55000;
						compression = 2500;
						damping = 8000;
						travelMaxUp = 0.095;
						travelMaxDown = 0.125;
					};
				};
			};
		};
	};

	class Truck_01_Cargo_Grey_FIX : Truck_01_Cargo_Grey
	{
		fuelCapacity = 120;
		fuelConsumption = 30;
		class SimulationModule
		{
			class Steering
			{
				maxSteeringAngle = 35;
				increaseSpeed[] = {0,25,50,15};
				decreaseSpeed[] = {0,50,50,40};
				centeringSpeed[] = {0,25,50,15};
			};
			class Throttle
			{
				reactionTime = 0.2;
				defaultThrust = 0.8;
				gentleThrust = 0.6;
				turboCoef = 1.15;
				gentleCoef = 0.5;
			};
			class Brake
			{
				pressureBySpeed[] = {0,0.5,10,0.46,30,0.43,40,0.35,60,0.4,80,0.5};
				gentleCoef = 0.6;
				minPressure = 0.2;
				reactionTime = 0.3;
				driverless = 0.1;
			};
			class Aerodynamics
			{
				frontalArea = 5.75;
				dragCoefficient = 0.53;
			};
			drive = "DRIVE_642";
			class Engine
			{
				torqueCurve[] = {525,0,1000,330,1400,340,1900,300,2500,100,3000,0};
				inertia = 3.25;
				frictionTorque = 100;
				rollingFriction = 3;
				viscousFriction = 2.5;
				rpmIdle = 650;
				rpmMin = 750;
				rpmClutch = 850;
				rpmRedline = 2400;
			};
			class Clutch
			{
				maxTorqueTransfer = 720;
				uncoupleTime = 0.2;
				coupleTime = 0.65;
			};
			class Gearbox
			{
				type = "GEARBOX_MANUAL";
				reverse = 6.28;
				ratios[] = {6.19,3.13,1.75,1.0};
			};
			class CentralDifferential
			{
				ratio = 0.75;
				type = "DIFFERENTIAL_LOCKED";
			};
			class Axles
			{
				class Front
				{
					maxBrakeTorque = 9000;
					wheelHubMass = 25;
					wheelHubRadius = 0.3;
					class Suspension
					{
						stiffness = 65000;
						compression = 3000;
						damping = 7000;
						travelMaxUp = 0.14;
						travelMaxDown = 0.15;
					};
				};
				class Middle
				{
					maxBrakeTorque = 6200;
					maxHandbrakeTorque = 12000;
					wheelHubMass = 45;
					wheelHubRadius = 0.3;
					class Differential
					{
						ratio = 8.35;
						type = "DIFFERENTIAL_LOCKED";
					};
					class Suspension
					{
						stiffness = 55000;
						compression = 2500;
						damping = 8000;
						travelMaxUp = 0.095;
						travelMaxDown = 0.125;
					};
				};
				class Rear
				{
					maxBrakeTorque = 6200;
					maxHandbrakeTorque = 12000;
					wheelHubMass = 45;
					wheelHubRadius = 0.3;
					class Differential
					{
						ratio = 8.35;
						type = "DIFFERENTIAL_LOCKED";
					};
					class Suspension
					{
						stiffness = 55000;
						compression = 2500;
						damping = 8000;
						travelMaxUp = 0.095;
						travelMaxDown = 0.125;
					};
				};
			};
		};
	};

	class Truck_01_Cargo_Orange_FIX : Truck_01_Cargo_Orange
	{
		fuelCapacity = 120;
		fuelConsumption = 30;
		class SimulationModule
		{
			class Steering
			{
				maxSteeringAngle = 35;
				increaseSpeed[] = {0,25,50,15};
				decreaseSpeed[] = {0,50,50,40};
				centeringSpeed[] = {0,25,50,15};
			};
			class Throttle
			{
				reactionTime = 0.2;
				defaultThrust = 0.8;
				gentleThrust = 0.6;
				turboCoef = 1.15;
				gentleCoef = 0.5;
			};
			class Brake
			{
				pressureBySpeed[] = {0,0.5,10,0.46,30,0.43,40,0.35,60,0.4,80,0.5};
				gentleCoef = 0.6;
				minPressure = 0.2;
				reactionTime = 0.3;
				driverless = 0.1;
			};
			class Aerodynamics
			{
				frontalArea = 5.75;
				dragCoefficient = 0.53;
			};
			drive = "DRIVE_642";
			class Engine
			{
				torqueCurve[] = {525,0,1000,330,1400,340,1900,300,2500,100,3000,0};
				inertia = 3.25;
				frictionTorque = 100;
				rollingFriction = 3;
				viscousFriction = 2.5;
				rpmIdle = 650;
				rpmMin = 750;
				rpmClutch = 850;
				rpmRedline = 2400;
			};
			class Clutch
			{
				maxTorqueTransfer = 720;
				uncoupleTime = 0.2;
				coupleTime = 0.65;
			};
			class Gearbox
			{
				type = "GEARBOX_MANUAL";
				reverse = 6.28;
				ratios[] = {6.19,3.13,1.75,1.0};
			};
			class CentralDifferential
			{
				ratio = 0.75;
				type = "DIFFERENTIAL_LOCKED";
			};
			class Axles
			{
				class Front
				{
					maxBrakeTorque = 9000;
					wheelHubMass = 25;
					wheelHubRadius = 0.3;
					class Suspension
					{
						stiffness = 65000;
						compression = 3000;
						damping = 7000;
						travelMaxUp = 0.14;
						travelMaxDown = 0.15;
					};
				};
				class Middle
				{
					maxBrakeTorque = 6200;
					maxHandbrakeTorque = 12000;
					wheelHubMass = 45;
					wheelHubRadius = 0.3;
					class Differential
					{
						ratio = 8.35;
						type = "DIFFERENTIAL_LOCKED";
					};
					class Suspension
					{
						stiffness = 55000;
						compression = 2500;
						damping = 8000;
						travelMaxUp = 0.095;
						travelMaxDown = 0.125;
					};
				};
				class Rear
				{
					maxBrakeTorque = 6200;
					maxHandbrakeTorque = 12000;
					wheelHubMass = 45;
					wheelHubRadius = 0.3;
					class Differential
					{
						ratio = 8.35;
						type = "DIFFERENTIAL_LOCKED";
					};
					class Suspension
					{
						stiffness = 55000;
						compression = 2500;
						damping = 8000;
						travelMaxUp = 0.095;
						travelMaxDown = 0.125;
					};
				};
			};
		};
	};
};
