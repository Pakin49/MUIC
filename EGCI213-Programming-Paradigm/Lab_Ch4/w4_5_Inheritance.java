package Lab_Ch4;

// ----- (3) add prefix final : cannot extend after final
// ----- (6) add extends Baby
class Man4 // extends Baby
{
    protected  String  name;
    protected  String  surname;
    protected  int     age;

    // Constructor
    public Man4() { } // add default constructor for error protection when extend to child class
    public Man4(String n, String s, int a)	{ name = n; surname = s; age = a; }
    // if extends baby the constructor will call super(); but the constructor of baby is private = error

    public void    setName(String n)    { name = n; }
    public void    setAge(int a)	{ age = a; }
    public String  getName()		{ return name; }
    public String  getSurname()		{ return surname; }
    public int     getAge()		{ return age; }

    // ----- (4) add prefix final
    public void speak()	
    { 
	System.out.printf("My name is %s %s \n", getName(), getSurname()); 
    }
};

//////////////////////////////////////////////////////////////////////////////////////////
class Woman4 extends Man4
{
    protected  boolean single;
    protected  String  maiden;
    protected  Man4    husband;
    // Default Constructor
    public Woman4(){}
    // Constructor
    public Woman4(String n, String s, int a)	
    { 
        super(n, s, a); // if there is no default constructor it will be error

            // ----- (1) comment the call to super(...) and uncomment the following
        //name = n; surname = s; age = a;

        single = true;
    }

    public void marriedTo(Man4 m)
    {
        // ----- (5) deep copy
	    husband = new Man4( m.getName(), m.getSurname(), m.getAge() );
        
        // ----- (5) shallow copy
        //husband = m;
        
	maiden  = surname;
	surname = husband.getSurname();
	single  = false;
    }

    // ------ (2) method overriding - change prefix from public to protected
    @Override
    public void speak()
    { 
	if (single == true)
            System.out.printf("My name is Miss %s %s \n", getName(), getSurname()); 
	else 
        {
            System.out.printf("My name is Mrs. %s %s %s \n", getName(), maiden, surname); 
            System.out.print("   Husband >> ");
            husband.speak();
        }
    }
    
    public void someAction()
    {
        speak();
        //this.speak();
        //super.speak();
    }
};

//////////////////////////////////////////////////////////////////////////////////////////
class Baby
{
    protected String nickname;

    // private constructor
    private Baby(String n) { nickname = n; }
    //static method to create baby
    public static Baby createBaby(String n)        
    { 
        Baby bb = new Baby(n);
        return bb;
    }
    public void cry()
    {
        System.out.printf("Baby %s cries \n", nickname);
    }
}
//////////////////////////////////////////////////////////////////////////////////////////
class w4_5_Inheritance
{
    public static void main(String[] args) 
    {
        w4_5_Inheritance mainApp = new w4_5_Inheritance();
        mainApp.testConstructor();
        mainApp.testPolymorphism();
    }
    
    public void testConstructor()
    {
	// ----- (1) constructor chain
	Man4   John = new Man4("John", "Smith", 20);
	Woman4 Mary = new Woman4("Mary", "Lee", 20);
	John.speak();
	Mary.speak();


	// ----- (2) method overriding
	System.out.println("\n\n--- Test overriding ---");
        Mary.someAction();

        
        // ----- (5) shallow vs. deep copy
        Mary.marriedTo(John);
        John.setName("Jack"); System.out.println(); Mary.speak();

        
        // ----- (6) class with private constructor
        System.out.println("\n\n--- Test private constructor ---");

        // Using normal constructor
        // Baby Apple = new Baby("Apple");
        // Static method to create baby, for complicated object
        // don't want user to create empty object, we create object inside your own method and
        Baby Apple = Baby.createBaby("Apple");
        Apple.cry();
    }
    
    public void testPolymorphism() {
        // ----- (7) polymorphism
        System.out.println("\n\n--- Test polymorphism ---");
        Man4 John = new Man4("John", "Smith", 20);
        Woman4 Mary = new Woman4("Mary", "Lee", 20);

        Man4[] M = new Man4[4];
        M[0] = John;
        M[1] = Mary;
        M[2] = new Man4("Bruce", "Willis", 50);
        M[3] = new Woman4("Sandra", "Bullock", 40);

        for (int i = 0; i < M.length; i++){
            M[i].speak();
        }
    }
}
