// Pakin Panawattanakul 6580043
package Ex6_6580043;

import java.io.*;
import java.util.*;

class OneCard {
    private int score; // 0-51
    private int suit; // clubs, diamonds, hearts, spades
    private int rank; // ace, 2-10, jack, queen, king

    public OneCard(int sc) {
        this.score = sc;
        // represent card suit by %4 result
        // 0 = club, 1 = diamonds, 2 = hearts, 3 = spades
        this.suit = sc / 13;
        // jack = 11, queen = 12, king =13
        this.rank = (sc%13)+1;
    }

    //Setter & Getter
    int get_score(){ return this.score;}
    String get_suit(){
        String s = "";
        if(this.suit==0){ s = "Clubs";}
        else if(this.suit==1){ s = "Diamonds";}
        else if(this.suit==2){ s = "Hearts";}
        else { s = "Spades";}
        return s;
    }
    String get_rank(){
        String r = "";
        if (this.rank == 1){r = "A";}
        else if (this.rank == 11){ r = "J";}
        else if (this.rank == 12){ r = "Q";}
        else if (this.rank == 13){ r = "K";}
        else { r = String.valueOf(this.rank);}
        return r;
    }
}

class CardThread extends Thread {
    private PrintWriter out;
    private ArrayList<OneCard> randomCards;

    private final int tid; // thread_id use for printing

    // Constructors
    public CardThread (int thread_num){ this.tid  = thread_num; randomCards = new ArrayList<>(); this.start();}

    //methods
    boolean check_rank(){
        String suit = randomCards.get(0).get_rank();
        boolean result = true;
        for(int i=1; i < 4; i++){
            if(!suit.equals(randomCards.get(i).get_rank())){
                result = false;
            }
        }
        return result;
    }
    boolean check_suit(){
        String suit = randomCards.get(0).get_suit();
        boolean result = true;
        for(int i=1; i < 4; i++){
            if(!suit.equals(randomCards.get(i).get_suit())){
                result = false;
            }
        }
        return result;
    }

    void print_cards(int round){
        out.printf("Round %3d  [",round);
        for(int i = 0; i < 4; i++){
            out.printf(" %2s of %-8s ",randomCards.get(i).get_rank(),randomCards.get(i).get_suit());
            if(i<3){
                out.printf(",");
            }
        }
        out.println("]\n");
    }
    void draw_cards(){
        Random random = new Random();
        for (int i = 0; i < 4; i++) {
            int rand_int = random.nextInt(52); // random integer

            // Detect if card is duplicated?
            boolean duplicate_card = false;
            for (OneCard randomCard : randomCards) {
                if (randomCard.get_score() == rand_int) {
                    duplicate_card = true;
                    break;
                }
            }
            if (duplicate_card) {
                i--;
                continue;
            }
            // If the card is not duplicate then at the card to the list
            randomCards.add(new OneCard(rand_int));
        }
    }

    @Override
    public void run() {

        String directory = "src/main/java/Ex6_6580043/T";
        String path = directory+this.tid+".txt";
        try {
            File out_file = new File(path);
            out = new PrintWriter(out_file);
        }catch (Exception e) {
            System.err.println(e.getClass().getName());
        }
            int round = 0;
            boolean finish = false;
            while (!finish) {
                draw_cards(); // draw 4 cards
                print_cards(round);//print the card in the ArrayList
                round += 1;
                if (check_suit() || check_rank()) {
                    finish = true;
                }
                randomCards.clear();
            }
            out.close();
            System.out.printf("Thread T%d finishes in %3d rounds\n", this.tid, round);
    }
}

public class Exercise_Ex6 {
    static ArrayList<CardThread> thread_list = new ArrayList<>();

    public static void main(String[] args) {
        // Scan for numbers of threads
        Scanner key_scan = new Scanner(System.in);
        System.out.println("Number of threads = ");
        int num_threads = 0;

        // If the input is not valid ask for another int
        while (true) {
            try {
                num_threads = key_scan.nextInt();
                break;
            } catch (RuntimeException re) {

                System.err.println("Enter valid integer");
                key_scan.nextLine();
            }
        }
        for (int i = 0; i < num_threads; i++) {
            thread_list.add(new CardThread(i));
        }
    }
}