package Lab_Ch4;

class Alien2
{
    //static private final int maxcount = 4; // final = const
    //static public int count = 0;
    static public String planet = "Mars";

    // ----- (4) use class constructor to initialize static members


    static private final int maxcount;
    static public int count;

    static public void startup() { System.out.println("\n=== Startup ===\n"); }
    static {
        maxcount = 4;
        count = 0;
        startup();
    }


    private String  name;

    // ----- (1) Object constructors - constructor chain
    private Alien2()				{ System.out.print("Alien "); }
    // java compiler will automatically add super();
    public Alien2(String n)			{ this(); name = n; System.out.println(name);}
    // calling constructor like creating method without creating object

    // ----- (2) static & non-static members
    public String getName()                     { return name; }
    //static public String getName()            { return name; }
    static public String getPlanet()            { return planet; }

    static public boolean arrive()
    {
        if (count < maxcount) return true;
        else return false;
    }

    // ----- (5) update final variable
    //static public void moreAliens(int m)		{ maxcount = m; }
};

/////////////////////////////////////////////////////////////////////////////////////////////
class w4_2_Members // java auto add => class w4_2_Members exten jva.lang.Object
{
    // auto add
    public w4_2_Members() {super();} // this is auto add
    public static void main(String[] args)
    {
        System.out.println("========== Program start ==========");
        String names[] = {"A", "B", "C", "D", "E", "F"};
        Alien2  a[]    = new Alien2[6];//create pointer to the object
        // Class Alien2 is mentioned so it will load the class into memory and called static block

	for (int i=0; i < a.length; i++)
	{
            // ----- (1) constructor
            a[i] = new Alien2(names[i]);

            if (i == 2) Alien2.planet = "Jupiter"; // class name access variable


            // ----- (2) call static member "arrive()" via class name
            //           notice that getName() must be called via object only
            if (Alien2.arrive()) //class name call static method
            {
                System.out.printf("***** %s welcomed at %s \n\n", a[i].getName(), Alien2.getPlanet());
                //System.out.printf("***** %s welcomed at %s \n\n", Alien2.getName(), Alien2.getPlanet());// cannot use class name to call non static method
                Alien2.count++;
            }

            /*
            // ----- (3) call static member "arrive()" via object
            if (a[i].arrive())
            {
                System.out.printf("***** %s welcomed at %s \n\n", a[i].getName(), a[i].getPlanet());
		a[i].count++;
            } // static method can be called from both object and class name but the best practice is class name
             */
	}

	// ----- (5) update final variable
	//Alien2.moreAliens(10);

	System.out.println();
    }
}