board_h = 21.5;
board_w = 28.5;
board_d = 8;

difference() {
  union() {
    translate([0,0,board_d]) cube([board_h+2, board_w+2, board_d+1]);
    //translate([0,0,-8]) #cube([board_h+2,board_w+2,8.1]);
    hull() {
      translate([0,0,board_d]) cube([board_h+2, board_w+2, 1]);
      translate([6,board_w/2-1,4]) cube([board_h-6, 4, 1]);

    }
    hull() {
      translate([12,board_w/2-1,0]) cube([board_h-14, 4, 5]);
      translate([0,board_w/2-1,8]) cube([board_h+2, 4, 1]);


    }

  }
  translate([1,1,board_d+1]) cube([board_h, 21, board_d+1]);
  translate([1,20.5,board_d+1]) #cube([7.5,11.5,board_d+1]);
  translate([-0.01, board_w/2, -0.01]) cube([board_h+3, 2, board_d]);
  translate([-0.01,board_w/2,3]) #cube([5, 2, board_d]);

}