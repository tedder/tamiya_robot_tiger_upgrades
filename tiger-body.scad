

difference() {
  hull() {
    cube([39,100,1]);
    // taper base
    translate([0,100-0.01,0]) hull() {
      cube([39,1,1]);
      translate([5/2,22-1,0]) cube([34,1,1]);
    }
    
    // round top
    intersection() {
      cube([39,122,39]);
      union() {
        translate([39/2,100,37-39/2]) rotate([90,0,0])
          cylinder(d=39, h=92, $fn=80);
        translate([34/2+5/2,122,37-34/2]) rotate([90,0,0])
          cylinder(d=34, h=22, $fn=80);
      }
    }

  }
  // notches on side
  //translate([-0.01,80,-0.01]) cube([39.02,24,1.1]);
  
  hull() {
    translate([39/2,100,37-39/2]) rotate([90,0,0])
      cylinder(d=37, h=90);
    translate([34/2+5/2,122.1,37-34/2]) rotate([90,0,0])
      cylinder(d=32, h=2, $fn=40);
    
    // leave the front end open for the taper
    translate([1,1,-0.01]) hull() {
      translate([0,10,37-39/2]) cube([37,89,0.01]);
      cube([37,99,0.01]);

    }
    
    // taper base cutout
    translate([1,100-0.01,-0.01]) hull() {
      cube([37,1,37-39/2]);
      translate([5/2,24.1,0]) cube([32.2,1,37-39/2]);
    }
  }
  
}