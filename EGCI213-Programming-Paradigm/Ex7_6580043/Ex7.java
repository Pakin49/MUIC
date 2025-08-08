// Pakin Panawattanakul 6580043
package Ex7_6580043;

import java.util.*;
import java.util.concurrent.*;

////////////////////////////////////////////////////////////////////////////////
class BankThread extends Thread
{
    private Account             sharedAccount;    
    private Exchanger<Account>  exchanger;         
    private CyclicBarrier       barrier;
    private int                 rounds;
    private boolean             modeD;                  //deposit (true) or withdraw (false)
    private boolean             first = true;
    private static volatile boolean running = true;
    // using volatile to make sure every thread doesn't use from the cache but main memory

    public BankThread(String n, Account sa, boolean m)  { 
        super(n); sharedAccount = sa; modeD = m;
    }
    public void setBarrier(CyclicBarrier ba)            { barrier = ba; }
    public void setExchanger(Exchanger<Account> ex)     { exchanger = ex; }
    public void setRounds(int r)    { this.rounds = r;}
    public static void stop_running() { BankThread.running = false;}
    @Override
    public void run(){
        // Loop for banking simulation. In each simulation:
        while(true) {
            try {
                //  (1) Wait for round from main thread
                barrier.await();
                if(!BankThread.running) {
                    break; // if round = -1 halt
                }
                //  (2) Deposit exchange
                if(first){ first = false;} // clear first flag --> next time Deposit thread exchange
                else{
                    if(this.modeD){
                        // deposit threads exchange account if not the first round
                        this.sharedAccount = exchanger.exchange(sharedAccount); // exchange account
                        System.out.printf("%s   >> exchange account\n", Thread.currentThread().getName()); // report
                    }
                }
                barrier.await(); //#2 wait for deposit thread swapping

                //  (3) Each thread identifies account it is managing in this simulation
                System.out.printf("%s   >> manage     %s (balance = %d)\n"
                        , Thread.currentThread().getName(), this.sharedAccount.getName(), this.sharedAccount.getBalance());

                barrier.await(); // #3 wait for every thread to identify account

                // (4) Each threads withdraw/deposit for #round
                for (int i = 0; i < this.rounds; i++) {

                    String head =  Thread.currentThread().getName()+ "   >> round " + (i + 1) + "    "; // pass thread name, round for deposit and withdraw
                    if (modeD) {
                        sharedAccount.deposit(head); // deposit threads deposit
                    } else {
                        sharedAccount.withdraw(head); // withdraw threads withdraw
                    }
                    barrier.await(); // wait for every round
                }

            } catch (InterruptedException | BrokenBarrierException e) { }
        }
    }
}

////////////////////////////////////////////////////////////////////////////////
class Account {
    private String  name;
    private int     balance;
    
    public Account(String id, int b)   { name = id; balance = b; }
    public String getName()            { return name; }
    public int    getBalance()         { return balance; }
    
    synchronized void deposit( String h)
    {
        Random random = new Random();
        int rand_int = random.nextInt(101); // Random money (1 to 100) to deposit
        this.balance += rand_int; // update balance
        System.out.printf(h+"%s %+4d  balance =%4d \n",this.name,rand_int, this.balance); // report

    }
    
    synchronized void withdraw(String h)
    {
        Random random = new Random();
        if ( this.balance!= 0){
            int rand_int = random.nextInt(this.balance/2); // Random money (1 to balance/2) to withdraw

            //if enough money
            if (rand_int <= this.balance) {
                this.balance -= rand_int;    // update the balance
                System.out.printf(h+"%s %+4d  balance =%4d \n", this.name, rand_int, this.balance); // report
            }
        }
        //if balance < withdraw or balance = 0
        else{
            System.out.printf(h+"%s  cannot withdraw\n",this.name); //report
        }
    }
}

////////////////////////////////////////////////////////////////////////////////
public class Ex7 {
    Account [] accounts;
    ArrayList <BankThread> allThreads;
    Exchanger <Account> exchanger;
    CyclicBarrier barrier;

    public static void main(String[] args) {
        Ex7 mainApp = new Ex7();
        try {
            mainApp.runSimulation();
        } catch(Exception e){ System.err.println(e.getClass().getName());}
    }

    public void runSimulation() throws Exception
    {
        simulation_init(); // setup threads, account, exchanger, cyclic barrier
        for (BankThread B : allThreads) { B.start(); } // Start all BankThreads

        Scanner keyscan = new Scanner(System.in);
        while(true){
            // (1) get number of simulation round from user
            int round = -1;
            boolean wrong_format = true; // if
            while(wrong_format){
                try {
                    System.out.printf("%4s >> Enter #rounds for a new simulation (-1 to quit)\n", Thread.currentThread().getName());
                    round = keyscan.nextInt();
                    keyscan.nextLine();
                    if(round < -1){
                        throw new RuntimeException();
                    }
                    wrong_format = false;
                }catch (RuntimeException re){ System.err.println("Invalid input!"); keyscan.nextLine();}
            }
            if ( round == -1 ) { break;} // if round = -1 finish the simulation

            // set round for simulation to every thread
            for ( BankThread B : allThreads){
                B.setRounds( round );
            }

            barrier.await(); // #1 check point for other thread to start
            barrier.await(); // #2 for the deposit thread exchange accounts
            barrier.await(); // #3 identify accounts

            for(int i = 0; i< round;i++){
                barrier.await(); // #4 all threads finish each rounds of withdraw/deposit
            }
            System.out.println();
        }
        // If user doesn't want to run a new simulation:

        BankThread.stop_running();
        barrier.await(); // release others thread to finished
        for(BankThread B : allThreads){
            B.join();
        }
        for(Account account : accounts){
            System.out.printf("%s >> final balance   %s = %d\n",Thread.currentThread().getName(),account.getName(),account.getBalance());
        }
        //   - Main thread reports final balances of all accounts
    }

    void simulation_init(){
        // Create accounts
        accounts = new Account[2];
        accounts[0] = new Account("account A", 0);
        accounts[1] = new Account(".".repeat(35) + "account B", 0);

        allThreads = new ArrayList<>(); //AL store both withdraw and deposit Threads
        exchanger     = new Exchanger<>(); // Exchanger for deposit threads

        // Creating Deposit threads
        allThreads.add( new BankThread("D1", accounts[0], true)); // D1 manage account A might swap later
        allThreads.add( new BankThread("D2", accounts[1], true)); // D2 manage account B might swap later
        for ( BankThread B: allThreads)     { B.setExchanger(exchanger); } // set exchanger for swapping accounts

        // Creating withdraw threads
        allThreads.add( new BankThread("W1",accounts[0],false)); // W1 manage account A
        allThreads.add( new BankThread("W2",accounts[1],false)); // W2 manage account B

        // Create Cyclic barrier and set to all threads
        barrier = new CyclicBarrier( allThreads.size()+1 ); // + 1 is main
        for ( BankThread B: allThreads)     { B.setBarrier( barrier ); }
    }
}
