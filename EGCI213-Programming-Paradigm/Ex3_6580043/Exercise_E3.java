// Pakin Panawattanakul 6580043
package Ex3_6580043;

//Import library
import java.util.*;
import java.io.*;
import java.util.stream.*;

public class Exercise_E3 {
    public static void main(String[] args)
    {
        Player[] allPlayer = new Player[12];

        String inPlayerPath = "src/main/java/Ex3_6580043/players.txt";
        try {
            File inFile = new File(inPlayerPath);
            Scanner fileScan = new Scanner(inFile);

            for(int i = 0;i<12;i++){
                //get line and split data into variable
                String line = fileScan.nextLine();

                String [] cols = line.split(",");
                String name = cols[1];
                int year = Integer.parseInt( cols[2].trim());

                switch (cols[0]) {
                    case "F":
                        int[] games = new int[3];
                        int[] goals = new int[3];
                        for (int j = 0; j < 3; j++) {
                            // split to games and goals
                            String[] subcols = cols[j + 3].split(":");
                            games[j] = Integer.parseInt(subcols[0].trim());
                            goals[j] = Integer.parseInt(subcols[1].trim());
                        }
                        allPlayer[i] = new FootballPlayer(name, year, games, goals);
                        break;

                    case "B":
                        int tol_games = Integer.parseInt(cols[3].trim());
                        int tol_min = Integer.parseInt(cols[4].trim());
                        int tol_point = Integer.parseInt(cols[5].trim());
                        allPlayer[i] = new BasketballPlayer(name,year,tol_games,tol_min,tol_point);
                        break;
                    default:
                        System.err.println("Nor Basketball or Football player");
                }
            }

            // Print personal data
            System.out.println("=== All player data (by reverse order) ===");
            for(int i = 11;i>=0;i--){
                allPlayer[i].printPersonalData();
            }
            // Print Football Player stat
            System.out.println("\n=== Football player statistics (by input order) ===");
            for(int i = 11;i>=0;i--){
                if(allPlayer[i] instanceof  FootballPlayer){
                    allPlayer[i].printStat();
                }
            }
            // Print Basketball Player stat
            System.out.println("\n=== Basketball player statistics (by input order) ===");
            for(int i = 11;i>=0;i--) {
                if (allPlayer[i] instanceof BasketballPlayer) {
                    allPlayer[i].printStat();
                }
            }
        }
        catch(Exception e){
            System.err.println(e.getMessage());
        }
    }
}

class Player {
    public static final int CURRENT_YEAR = 2025;
    private String name;
    protected int birthyear;
    protected int age;

    // Constructor
    public Player(){ }
    public Player(String nm, int by) {
        this.name = nm;
        this.birthyear = by;
        this.age = Player.CURRENT_YEAR - this.birthyear;
    }

    public String getName() { return name; }
    public void printPersonalData() { /* override this in child class */ }
    public void printStat() { /* override this in child class */ }
}

class FootballPlayer extends Player{
    protected int [] games;
    protected int [] goals;
    protected double [] avg_goals;

    // Constructor
    public FootballPlayer(){ } //empty Constructor
    public FootballPlayer(String nm,int by,int[] gm, int [] gl){
        super(nm,by);
        this.games = gm;
        this.goals = gl;
        this.avg_goals = new double[3];
        for(int i = 0;i<3;i++) {
            this.avg_goals[i] = (double) this.goals[i] / this.games[i];
        }
    }

    @Override
    public void printPersonalData(){
        System.out.printf("%-25s born %4d    age = %d\n",super.getName(),super.birthyear,super.age);
    }
    @Override
    public void printStat(){
        int total_games = IntStream.of(this.games).sum();
        int total_goals = IntStream.of(this.goals).sum();
        double goal_per_game = (double)total_goals/total_games;
        System.out.printf("%-25s total games = %3d    total goals = %3d (%1.2f per game)     last season goals =%3d\n",super.getName(),total_games,total_goals,goal_per_game,goals[2]);
    }
}

class BasketballPlayer extends Player{
    protected int total_games;
    protected int total_mins;
    protected int total_pts;
    protected double avg_mins;
    protected double avg_pts;

    // Constructor
    public BasketballPlayer() { }
    public BasketballPlayer(String nm,int by,int tol_game,int tol_min,int tol_point) {
        super(nm,by);
        this.total_games = tol_game;
        this.total_mins = tol_min;
        this.total_pts = tol_point;
        this.avg_mins = (double)tol_min/tol_game;
        this.avg_pts = (double)tol_point/tol_game;
    }

    @Override
    public void printPersonalData() {
        System.out.printf("%-25s born %4d    age = %d\n",super.getName(),super.birthyear,super.age);
    }
    @Override
    public void printStat(){
        System.out.printf("%-25s total games = %3d    total mins = %4d (%2.2f per game)    total points = %4d (%2.2f per game)\n",super.getName(),this.total_games,this.total_mins,this.avg_mins,this.total_pts,this.avg_pts);
    }
}

