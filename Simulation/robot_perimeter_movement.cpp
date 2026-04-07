/*
Problem:
---------
Design a Robot that moves along the boundary of a rectangular grid of size width x height.
- The robot starts at (0, 0) facing East.
- It moves only along the perimeter in a clockwise direction.
- Given a number of steps, move the robot accordingly.
- Return its final position and direction.

Key Observations:
----------------
1. The robot only travels on the boundary → total cycle = perimeter.
2. Perimeter = 2 * (width + height) - 4
3. Movement repeats after every full cycle → use modulo.
4. Directions follow order:
   East → North → West → South → repeat

Approach:
---------
1. Maintain current position (x, y) and direction (dir).
2. Reduce steps using modulo with perimeter.
3. Handle special case:
   - If num % perimeter == 0 and robot is at origin → direction becomes South.
4. Simulate movement direction by direction:
   - Move as much as possible in current direction
   - If boundary reached, change direction clockwise
5. Continue until all steps are consumed.

Time Complexity:
----------------
- O(1) per step() call
  (Because movement is bounded by 4 directions, not by num)

Space Complexity:
-----------------
- O(1)
*/

class Robot {
public:
    int x=0,y=0;
    int w,h,perimeter;
    int dir=0; // 0: East, 1: North, 2: West, 3: South

    Robot(int width, int height) {
        w=width;
        h=height;
        perimeter=2*(w+h)-4;
    }
    
    void step(int num) {
        if(perimeter==0) return;

        num%=perimeter;

        // Special case handling
        if(num==0 && (x!=0 || y!=0)) return;
        if(num==0 && x==0 && y==0) {
            dir=3; // South
            return;
        }

        while(num>0){
            if(dir==0){ // East
                int move=min(num,w-1-x);
                num-=move;
                x+=move;
                if(num>0) dir=1;
            }
            else if(dir==1){ // North
                int move=min(num,h-1-y);
                y+=move;
                num-=move;
                if(num>0) dir=2;
            }
            else if(dir==2){ // West
                int move=min(num,x);
                x-=move;
                num-=move;
                if(num>0) dir=3;
            }
            else{ // South
                int move=min(num,y);
                y-=move;
                num-=move;
                if(num>0) dir=0;
            }
        }
    }
    
    vector<int> getPos() {
        return {x,y};
    }
    
    string getDir() {
        if(dir==0) return "East";
        else if(dir==1) return "North";
        else if(dir==2) return "West";
        return "South";
    }
};
