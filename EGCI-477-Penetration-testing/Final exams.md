### You are hired to conduct a penetration test for a mid-sized healthcare provider. The customer requires that no scanning be performed on their live patient management database due to its fragility. Additionally the test must ensure compliance with HIPPA.

#### (a) describe how you would develop the scope and rules of engagement for this test.

There are several concerns when develop the scope especially in the sensitive industry like healthcare. In healthcare related business information of patient both life and archive are extremely confidential which make the confidentiality and the non-disclosure agreement even more important.
When developing the scope pentester and clients have to discuss targets that will be test and will **not** be test. The targets that will be test can include many type
	1. Network : which subnet will the test will performed on and is there any ip address where you should not performed test on
	2. Systems : which system that will included in the test e.g. The web server, file sharing system using SMB protocols use by employees
	3. Applications : The web applications are another attacking surface that hacker can use to attack and gathering information
there are not enough people that know about security and many developer can leave security hole in there code especially when it is mid-sized healthcare provider, which might lack resources and knowledge.

Rules of engagement
	1. Testing timeline : can use Gantt chart to visualize
	2. Location of testing
	3. Time of testing 
	4. Communication methods
	5. Security features that could prevent testing : e.g. firewall
	6. Scope : mention in the scope section above
	7. Which type of test are allow and not allow to perform
#### (b) What key elements must be consider

## Question 2 : Your team is preparing to test a financial services web application. The client wants assurance that your approach is repeatable and aligned with industry best practices.

#### (a) which penetration testing methodology would you use and how would it guide your process?

If we talk about web application we cannot forget to mention about the OWASP web security testing guide. WSTG provide guideline to test security of website base on TOP 10 vulnerability founded in web application. 
1. Information gathering : we can use both passive and active recon tools eg. dig,host,ns, look up, nmap
2. Authentication : We can test the strength of password, e.g. using hydra to bruteforce, or metasploit to check the unauthenticate login is allow or not
3. Session management : check if session info are encrypted or show in the url of the website. If it is not set up properly this lead to session hijacking, or attacker could gain information about the website
4. Input validation : If use input are not filter, it could lead to injection attack especially, SQL injection and XSS, we can use SQL map and 
5. Business logic testing : developer might leave a logic flaw in the system that we can abuse 
6. Client side testing : burp suite or OWASP zap to intercept and alter the information .
This guide line can help us structure and right the timeline for testing the client's website

we also need to consider about compliance if the client also handling about credits card. We need to consider the PCI DSS to follow standard
#### (b) why is this methodology suitable for financial sectors

because OWASP is a reliable and many organisation use as standard, it cover most common vulnerability, repeatable and up to standard as our client requested. We included both automate and manual test to make sure that the results are accurate. We also include the compliance PCI DSS into consideration to include industrial specific concern that might not include in the OWASP which are for more general use


###  3. During an internal test, you discover that the domain "corp.internal" has several exposed services. Your goal is to perform enumeration, vulnerability scanning and vulnerability exploitation on this domain

#### (a) which tools would you use ?
before we can enumerate the website we need to know the IP address of the corp.internal first in this step we can use host,dig,ns-lookup to find the correct IP address, then after we get the IP address of the  corp.internal we first scan the target we can use the active recon to scan what kind of service the corp.internal is running -> after that we start to do the vulnerability scanning
**vulnerability scanning** we can use : greenbone, to scan for the vulnerabilty,  there alternative 
#### (b) how would you apply them effectively