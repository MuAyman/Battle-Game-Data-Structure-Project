# Castle-DataStructre-Project

A castle that's being attacked by enemies and those enemies occupy one of the three states (active, frozen, killed).
Your system (your program) will receive the information about a list of enemies as input from an input file. This list represents the scenario to be simulated. For each enemy, the system will receive the following information:
            - Arrival Time stamp (Enemy Arrival Time): When the enemy arrives. 
            - Health: The starting health of the enemy.
            - Power: The power of the enemy.
            - Reload Period: Time for an enemy to reload its weapon.
            - Speed: number of meters an enemy can move in a single time step.
            - Type: fighter, freezer, or healer
            
# Simulation Approach & Assumptions
You will use incremental time simulation. You will divide the time into discrete time steps of 1-time unit each and simulate the changes in the system in each time step.
Definitions

❑ Enemy Types: There are three types of enemies: fighter, healer, and freezer
  ▪ Fighter can attack the castle and cause damage to the castle.
  ▪ Healer can heal other enemies and does not attack the castle.
  ▪ Freezer can throw ice on the castle to frost it for some time.
  
❑ Enemy Status: At any time, an enemy should be in one of four states: inactive (not arrived yet), active, frosted (both are described below) or killed (health <= 0). Only active enemies can act (fight/heal/freeze).

❑ Active Enemy: it is an enemy with Arrival Time ≤ current time step & Health > 0.

❑ Frosted Enemy: Frosted enemies cannot move or attack the castle. Any active enemy can be frosted for some time steps (freezing time) due to an attack from the castle.

❑ Enemy distance: it is the horizontal distance between the enemy and the castle.

❑ Reload Period: it is an interval where enemies are reloading their weapons. During reload period enemies cannot act (i.e. cannot attack or heal) but can move. Once reload period is over, enemies can act again.
   ▪ For example, Enemy e1(arrival time=5, reload period=3) will act at time step 5 and then wait to reload at time steps: 6, 7, and 8 then it will act again at time step 9 and then wait to reload at 10, 11 and 12 then act at 13 and so on.

# Game Rules
- Each enemy has its own speed and its own firepower.
- All enemies start at 60 meters distance from the castle.
- In general, an enemy moves at its original speed each time step. But an enemy with (health < 1/2 its original health) moves at its half-original speed.
- The minimum possible distance for any enemy to approach the castle is 2 meters.
- Enemies can move at their reload period but cannot act. (cannot fire nor heal)
- Movement Patterns: By default, all enemies move in the forward direction (approaching the castle) but only healers can move backward. When a healer reaches the end of the forward direction, it starts moving backward until it reaches the end of the backward direction where it turns back and moves forward again, and so on.
- Healer can heal only enemies that are at most 2 meters ahead in his moving direction.
- Healer cannot heal killed enemies. The healer cannot heal frosted enemies.
- A castle can attack any enemy type.
- Both castle and enemies can attack each other at the same time step.
- A castle can attack at most N enemies at each time step. (N is loaded from the input file).
- A castle can either fire bullets or throw ice to freeze an active enemy.
- At random time steps the castle throws ice instead of bullets. The percentage of ice fires should be around 20% of all castle fires.
-  If Castle kills a healer within a distance of 5 meters from the castle, it uses the healer's tools to recover its health by a percentage of 3%.
- If an active enemy is hit by castle ice, it gets frosted for some time steps until the ice melts (See formulas section below).
- A frosted enemy is affected by castle fire but is not affected by castle ice.
- A frosted castle cannot attack enemies.
- A frosted castle is affected by fighter attacks only. Freezer enemy has no effect on it.
- The game is “win” if all enemies are killed. The game is “loss” if the castle is destroyed. Otherwise, the game is "drawn".

# Enemies picking criteria:
As mentioned in the game rules, a castle picks at most N enemies (in total) to attack at each time step. Attack means to fire bullets or to throw ice with a certain probability. The criteria to pick an enemy to attack are as follows:
          
          1. First attack fighters. The castle should pick fighters depending on their distance, power, and health, status (active or frosted), remaining time steps for an enemy to end reload period. Think about a suitable formula to give priority to each fighter according to at least four of the above factors. Then pick higher-priority fighters first.
          2. Then (if N is not exhausted yet), pick healers to attack. A fresh healer who has just joined the forces is picked first. This means that healers are picked in the reverse order of their arrival (Last-Come-First-Serve)
          3. Finally (if N is not exhausted yet) pick freezers to attack. A freezer that arrived first
should be attacked first (First-Come-First-Serve).



   
