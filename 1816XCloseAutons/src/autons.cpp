#include "vex.h"

void default_constants(){
  chassis.set_drive_constants(10, 1.5, 0, 10, 0);
  chassis.set_heading_constants(6, .4, 0, 1, 0);
  chassis.set_turn_constants(12, .4, .03, 3, 15);
  chassis.set_swing_constants(12, .3, .001, 2, 15);
  chassis.set_drive_exit_conditions(1.5, 300, 5000);
  chassis.set_turn_exit_conditions(1, 300, 3000);
  chassis.set_swing_exit_conditions(1, 300, 3000);
}

void odom_constants(){
  default_constants();
  chassis.drive_max_voltage = 8;
  chassis.drive_settle_error = 3;
}

void drive_test(){
  chassis.drive_distance(6);
  chassis.drive_distance(12);
  chassis.drive_distance(18);
  chassis.drive_distance(-36);
}

void turn_test(){
  chassis.turn_to_angle(5);
  chassis.turn_to_angle(30);
  chassis.turn_to_angle(90);
  chassis.turn_to_angle(225);
  chassis.turn_to_angle(0);
}

void swing_test(){
  chassis.left_swing_to_angle(90);
  chassis.right_swing_to_angle(0);
}

void full_test(){
  chassis.drive_distance(24);
  chassis.turn_to_angle(-45);
  chassis.drive_distance(-36);
  chassis.right_swing_to_angle(-90);
  chassis.drive_distance(24);
  chassis.turn_to_angle(0);
}

void odom_test(){
  chassis.set_coordinates(0, 0, 0);
  while(1){
    Brain.Screen.clearScreen();
    Brain.Screen.printAt(0,50, "X: %f", chassis.get_X_position());
    Brain.Screen.printAt(0,70, "Y: %f", chassis.get_Y_position());
    Brain.Screen.printAt(0,90, "Heading: %f", chassis.get_absolute_heading());
    Brain.Screen.printAt(0,110, "ForwardTracker: %f", chassis.get_ForwardTracker_position());
    Brain.Screen.printAt(0,130, "SidewaysTracker: %f", chassis.get_SidewaysTracker_position());
    task::sleep(20);
  }
}

void tank_odom_test(){
  odom_constants();
  chassis.set_coordinates(0, 0, 0);
  chassis.turn_to_point(24, 24);
  chassis.drive_to_point(24,24);
  chassis.drive_to_point(0,0);
  chassis.turn_to_angle(0);
}

void holonomic_odom_test(){
  odom_constants();
  chassis.set_coordinates(0, 0, 0);
  chassis.holonomic_drive_to_point(0, 18, 90);
  chassis.holonomic_drive_to_point(18, 0, 180);
  chassis.holonomic_drive_to_point(0, 18, 270);
  chassis.holonomic_drive_to_point(0, 0, 0);
}

void defensive_side_auton_1(){
  chassis.set_drive_constants(300, 1.0, 0.4, 10.0, 1.5);
  chassis.set_heading_constants(6, .4, 0, 1, 0);
  chassis.set_turn_constants(12, .4, .03, 3, 15);
  chassis.set_swing_constants(40, .4, .03, 3, 15);
  chassis.drive_settle_error = 5;
  chassis.drive_settle_time = 1;
  Intake.setVelocity(200, rpm);
  // chassis.set_coordinates(35, 13, 15);
  Intake.spin(forward);
  // chassis.drive_to_point(48, 64);
  Intake.spin(forward);
  chassis.drive_distance(51);
  wait(0.4, seconds);
  chassis.drive_distance(-51);
  chassis.turn_to_angle(-60);
  chassis.drive_distance(19);
  BackWings.set(true);
  chassis.left_swing_to_angle(-105);
  BackWings.set(false);
  chassis.left_swing_to_angle(-60);
  chassis.drive_distance(-18);
  chassis.turn_to_angle(75);
  Intake.spin(reverse);
  chassis.drive_distance(36);
  chassis.drive_distance(-36);
  chassis.right_swing_to_angle(105);
  chassis.drive_distance(-20);
  BackWings.set(true);
}

void defensive_side_auton_2() {
  chassis.set_drive_constants(300, 1.0, 0.4, 10.0, 1.5);
  chassis.set_heading_constants(6, .4, 0, 1, 0);
  chassis.set_turn_constants(12, .4, .03, 3, 15);
  chassis.set_swing_constants(40, .4, .03, 3, 15);
  chassis.drive_settle_error = 5;
  chassis.drive_settle_time = 1;
  Intake.setVelocity(600, rpm);
  BackWings.set(false);
  Intake.spin(forward);
  chassis.drive_distance(12);
  BackWings.set(true);
  chassis.left_swing_to_angle(-40);
  BackWings.set(false);
  chassis.turn_to_angle(0);
  chassis.drive_distance(-8);
  chassis.turn_to_angle(135);
  Intake.spin(reverse);
  chassis.drive_distance(38);
}

void defensive_side_auton_3() {
  chassis.set_drive_constants(300, 1.0, 0.4, 10.0, 1.5);
  chassis.set_heading_constants(6, .4, 0, 1, 0);
  chassis.set_turn_constants(12, .4, .03, 3, 15);
  chassis.set_swing_constants(40, .4, .03, 3, 15);
  chassis.drive_settle_error = 5;
  chassis.drive_settle_time = 1;
  Intake.setVelocity(200, rpm);
  FrontWings.set(false);
  //chassis.set_coordinates(-34, -56, 5);
  Intake.spin(forward);
  //chassis.drive_to_point(-24, 0);
  chassis.drive_distance(51);
  wait(0.2, seconds);
  chassis.drive_distance(-5);
  chassis.turn_to_angle(-105);
  chassis.drive_distance(-17);
  FrontWings.set(true);
  wait(0.1, seconds);
  chassis.turn_to_angle(-11);
  wait(0.3, seconds);
  FrontWings.set(false);
  wait(0.2, seconds);
  chassis.drive_distance(-6);
  chassis.turn_to_angle(165);
  FrontWings.set(true);
  chassis.drive_distance(31);
  wait(0.2, seconds);
  chassis.drive_distance(-23);
  FrontWings.set(false);
  chassis.turn_to_angle(30);
  chassis.drive_distance(-43.3);
  chassis.turn_to_angle(-60);
  chassis.drive_distance(10);
  BackWings.set(true);
  wait(0.4, seconds);
  chassis.drive_distance(3);
  chassis.left_swing_to_angle(-105);
  BackWings.set(false);
  chassis.left_swing_to_angle(-60);
  chassis.drive_distance(-20);
  chassis.turn_to_angle(75);
  Intake.spin(reverse);
  chassis.drive_distance(38);
  chassis.drive_distance(-38);
}

void offensive_side_auton_1() {
  chassis.set_drive_constants(300, 1.0, 0.4, 10.0, 1.5);
  chassis.set_heading_constants(6, .4, 0, 1, 0);
  chassis.set_turn_constants(12, .4, .03, 3, 15);
  chassis.set_swing_constants(40, .4, .03, 3, 15);
  chassis.drive_settle_error = 5;
  chassis.drive_settle_time = 1;
  Intake.setVelocity(200, rpm);
  Intake.spin(forward);
  wait(0.2, seconds);
  chassis.drive_distance(-40);
  chassis.turn_to_angle(-45);
  BackWings.set(true);
  wait(0.5, seconds);
  chassis.drive_distance(-20);
  BackWings.set(false);
  chassis.drive_distance(-10);
  chassis.left_swing_to_angle(-90);
  chassis.drive_distance(-15);
  chassis.drive_distance(8);
  chassis.turn_to_angle(90);
  Intake.spin(reverse);
  chassis.drive_distance(22);
  Intake.stop();
  chassis.drive_distance(-22);
  chassis.turn_to_angle(25);
  Intake.spin(forward);
  chassis.drive_distance(54);
}
