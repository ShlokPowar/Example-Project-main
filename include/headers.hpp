//Intake
static pros::Motor intake(3, MOTOR_GEARSET_06, false, MOTOR_ENCODER_DEGREES);

//indexers
// static pros::ADIDigitalOut index1('C', false);
static pros::ADIDigitalOut indexer('H', false); // triple
static pros::ADIDigitalOut indexerSingle('G', false); // single

//flywheel
static pros::Motor flywheel(6, MOTOR_GEARSET_06, true, MOTOR_ENCODER_DEGREES);

// expansion(s)
static pros::ADIDigitalOut expansion('A', false);
// static pros::ADIDigitalOut expansion2('B', false); // this is if you decide to use a second solenoid for the other piston

void drive(double, float);