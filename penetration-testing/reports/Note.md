---
aliases:
---
.#### Ninny's : cheat sheets  
https://github.com/NitchayaninT/EGCI477_Pentest/blob/main/Cheat%20Sheets/README.md

# Chapter 3 : Scan and Recon (it gives you targets)

## 3.1 Overview
- Passive Recon: not intrusive, just listening to network; good for not disrupting production or avoiding detection  
- Active Recon: sending probes to network/target; more intrusive (has many levels of aggressiveness)

## 3.2 Passive Reconnaissance

#### 1. OSINT: Public info gathering from internet, social media, etc.  
   2. **SpiderFoot (GUI)**: GUI tool using OSINT databases to search  
      - Domain names  
      - IP addresses  
      - Subnet addresses  
      - Autonomous System Numbers (ASN)  
      - Email addresses  
      - Phone numbers  
      - Personal names  
   3. **recon-ng (CLI)**: Similar to SpiderFoot but more modular; uses OSINT frameworks with downloadable modules  

#### 2. DNS Lookup: Search for IP addresses, services running on servers  
1. `dig`  :  e.g. `dig {hostname} MX` for email server  
2. `nmap`  
3. `nslookup`  
4. `host`  

#### 3. Find technical and administrative contact  
   - Who owns `<domain name>`  
   - Sometimes server is hosted on cloud  
     - e.g. `host netflix.com` returns IP  
     - `whois <IP>` shows Amazon because Netflix hosts on Amazon AWS  

#### 4. Social media scripting:  
   - Find info about organization based on social media (Facebook, LinkedIn, etc.)  
   - Job postings or responsibilities reveal tech stack to use in attack phase  

#### 5. Cryptographic Flaws:  
   - Use `crt.sh` to find cryptographic info  
   - Because of Certificate Transparency, hackers can gather info from the website  

#### 6. Company Reputation and Security Posture: security breach → info leaks still on internet  
   **Data types:**  
   - Password dumps  
   - File metadata  
   - Strategic search engine analysis/enumeration  
   - Website archiving/caching  
   - Public source code repositories  

   **Tools:**  
   - h8mail  
   - WhatBreach: https://github.com/Ekultek/WhatBreach  
   - LeakLooker: https://github.com/woj-ciech/LeakLooker  
   - Buster: https://github.com/sham00n/buster  
   - Scavenger: https://github.com/rndinfosecguy/Scavenger  
   - PwnDB: https://github.com/davidtavarez/pwnd  
   - ExifTool (extract metadata of image/audio/video/docs etc.)  

   **Google hacking operators:**  
   - **filetype:** Search only within a specific file type (e.g., `filetype:xls`)  
   - **inurl:** Search within URLs containing a term (e.g., `inurl:search-text`)  
   - **link:** Search for pages linking to a URL (e.g., `link:www.domain.com`)
   - **intitle:** Search within page titles for a term (e.g., `intitle:"Index of /etc"`)  

   Google hacking DB: _[https://www.exploit-db.com/google-hacking-database/](https://www.exploit-db.com/google-hacking-database/)_

## 3.3 Active Recon

Information gathering is called **enumeration**.  
First, do passive recon to find targets → know the target → test which ports respond to probes (e.g., send TCP SYN to test if port is listening).

#### 1. **nmap**: Sending probes (packets) to ports according to their protocol  
nmap [ options ] < ip address> 

   ***Most use***
	- `-sn` : Host discovery
	- `-sT` : TCP connection (default)
	- `-sS` : TCP SYN stealth scan
	- `-sF` : TCP FIN scan
	- `-p` : Specify ports (e.g., `-p 80,443` or `-p-` all)
	- `-A` : Aggressive scan (OS, version, scripts, traceroute)
	- `-sV` : Service/version detection
	- `-O` : OS detection
	- `-Pn` : No ping (skip host discovery)
	- `-v` : Verbose output
	- `--script` : Run NSE scripts (e.g., `--script vulners`)
	- `-T` : Timing template (0–5, faster at higher)
	- `-oA` : Output in all formats (normal, XML, grepable)
	*note* : nmap only scan the most popular 1000 ports for the protocal (use -p to specify port)

##### **UDP Scan Result Interpretation**  
nmap -sU

| Response         | Port Status | Description                          |
| ---------------- | ----------- | ------------------------------------ |
| Data returned    | open        | Service is listening and responded   |
| ICMP error       | closed      | Service is not listening on the port |
| No ICMP response | open        | The port is fire walled/time out     |

#### **TCP Scan Result Interpretation**  
nmap -sT

| Response         | Port Status | Description                    |
| ---------------- | ----------- | ------------------------------ |
| SYN/ACK          | open        | Port is listening              |
| RST              | closed      | Port is reachable but not open |
| No response      | filtered    | Likely filtered by firewall    |
| ICMP unreachable | filtered    | Host/port unreachable          |
sometimes the port is fltered by fire wall when when we send TCP SYN -> we need to fine new method : sending TCP FIN instead

| Response         | Port Status | Description                        |
| ---------------- | ----------- | ---------------------------------- |
| ICMP unreachable | filtered    | Close port should respond with RST |
| RST              | close port  | Close port should respond with RST |
| No resopnd       | open/filter | Open port should drop FIN          |

#### Host discovery scan  
nmap -su < subnet > , eg . nmap -su 192.168.0.0/24  
scan for finding host not scan for finding port  

**NOTE** The default for the -sn scan option is to send an ICMP echo request packet to the target, a TCP SYN to port 443, a TCP ACK to port 80, and an ICMP timestamp request.

#### Timing option
-Tx : value of x = `[0-5]`, 0 is very slow, 5 is very aggressive

## Enumeration type
- Host enum : finding host in the subnet -> nmap -su `<subnet>`, nmap -sp `<subnet>` for ping scan
- User enum (SMB): finding user information ( username, password) using **SMB** ( server message block) protocal, **TCP** port 445,  if the message is not encrypted properly we can get data the user
  e.g. **nmap --script smb-enum-users.nse**  `<host>`
- Group enum (SMB): find group to find authorization rowU
  e.g. nmap --script smb-enum-groups.nse -p445 `<host>`
- Network share enum (SMB) : Identify system on the shared network use for sharing files, folders, printers,
  **nmap --script smb-enum-shares.nse -p 445** `<host>
- Additional SMB enum (SMB): additional fingerprint of applications and OS running on the target
  **nmap -sC**
**NOTE** You can locate the installed NSE scripts in Kali Linux and Parrot OS by simply using the **locate *.nse** command. The site _[https://nmap.org/book/man-nse.html](https://nmap.org/book/man-nse.html)_
- Web page / Web Application Enumerations
  after knowing the host and user -> now we need attack surface (we know that username password where do we use it?) -> **nmap -sV**  --script=http-enum `<target>`\ this serach through the common directory in the target ip adress 
  eg.  /admin,/login,/phpinfo.php
  alternative tools is **nikto -h `<target>**
- Service enum : if you already know the user credential from previous enumerations then we can use this
```
nmap --script smb-enum-processes.nse --script-args smbusername=<username>,smbpass=<password> -p445 <host>
```
- packet crafting : use scapy (I don't give a shit)
## **Art of performing vulnerability scan**
after we find the target from **passive recon & active recon** and what type of services the host are running. We use **vulnerability scanning tools** to find weakness in those services. It finds vulnerability by comparing the scan result to the previously know vulnerability 
Most the time the results are fault positives -> recheck for correctness. 
- **Step 1**: Use tools like Nmap for host and port enumeration; probe open ports for more info.  
- **Step 2**: Identify software and version on open ports (e.g., via banners); store results in a database.  
- **Step 3**: Match discovered services against known vulnerabilities using a vulnerability database.  
- **Step 4**: Generate a report of potential vulnerabilities (may contain false positives; validate findings)
#### Scan types
1. **Unauthenticated Scan** 
   default , does not use credential just scan all port in the given IP. Sometimes when the port is fire walled or does not respond it does not mean that we cannot connect to it so it's might be good to run Authenticated scan if possible.
   **note** normally Authenticate scan provide less false positive than Unauthenticate
2. **Authenticate Scan**
   Use user credential get from step 1 and 2. The tool sometimes use ssh into the target and run the scan **e.g. netstat** 
3. **Discovery Scans** 
   Finding attack surface of a target. Performs both passive and active recon for us, e.g. **nmap** or other tools.
4. **Full Scan**
   Scan every options available, provide a lot of traffics. Might need to adjust plugin sections to reduce the unused scanning tools
5. **Stealth scan**
   Less intrusive good for testing in a production state, normally scanner provide a lot of traffic but we can make it scan quieter. e.g. passive vulnerability scanner.
6. **Compliance scan**
   Scan base on market or government standard.
#### **Understanding scan result***
- Running a scan is easy; the hard part is analyzing results.
- Scanners often produce false positives → wastes time and causes friction (e.g., with endpoint teams or clients).
- Inaccurate reports hurt credibility, especially in professional pen-testing
####  How to Reduce False Positives:
- Check how the scanner detected the issue (credentialed scan = more accurate).
- Manually verify version info and configuration on the target. 
- Review associated CVE details to confirm actual exploitability.
- Be aware of backporting (patched software may still report old version numbers).
- Best validation method = try to exploit the vulnerability (where legal/ethical).
#### Steps to Manually Verify a CVE (by chatGPT
1. **Identify the CVE ID**
    - Example: `CVE-2021-41773`
2. **Read CVE Details**
    - Go to https://cve.mitre.org or [https://nvd.nist.gov](https://nvd.nist.gov)
    - Check
        - Affected software & versions
        - Exploit conditions
        - Mitigation info
            
3. **Check Target Software Version**
    - Manually query the service (e.g., `httpd -v`, `nginx -v`)
    - Or inspect configuration files/logs for package version
4. **Check for Backporting**
    - Use `changelog`, package notes, or vendor docs to see if the patch is already applied under the same version
5. **Match Conditions**
    - Verify the exploit conditions match your target (e.g., OS version, configs, modules enabled)
6. **Attempt Safe Proof-of-Concept (PoC) Test** _(Optional but best)_
    - Use a known PoC from GitHub or Exploit-DB
    - Run in a test or isolated environment
7. **Document Your Findings**
    - Record evidence: version, method used, and whether the system is vulnerable or no
  **This are website you should look into**
- **CVE** lists vulnerabilities that have been discovered
- **CWE** classifies these vulnerabilities by type or weakness 
- **NVD** provides detailed information and analysis
- **CVSS** gives severity ratings for the vulnerabilities

# Module4 : Exploiting Wired and Wireless network

After we have access to the host or know the vulnerability of the host now it is time to exploit to demonstrate the weakness of the system

This chapter is focusing on understanding tactics that **thread actor** use to exploit
## Network-based vulnerability
**common attacks and exploits**
- Windows name resolution-based attacks and exploits
- DNS cache poisoning attacks
- Attacks and exploits against Server Message Block (SMB) implementations
- Simple Network Management Protocol (SNMP) vulnerabilities and exploits
- Simple Mail Transfer Protocol (SMTP) vulnerabilities and exploits
- File Transfer Protocol (FTP) vulnerabilities and exploits
- Pass-the-hash attacks
- On-path attacks (previously known as man-in-the-middle [MITM] attacks)
- SSL stripping attacks
- Denial-of-service (DoS) and distributed denial-of-service (DDoS) attacks
- Network access control (NAC) bypass
- Virtual local area network (VLAN) hopping attacks

**<u>Plan use in CISCO</u>**
- Find the target : Host enumeration and Services enumeration
- Focus on : network with proprietary data
- Scan for weakness : Using scanning tools
- Plan which exploit to use for risk analysis
- Network share Enumeration & using **on path attacks (Man In The Middle attack)** to gain unauthorized access and data
#### 1. Windows Name Resolution and SMB attacks
Exploit the conversion between **Name** <-> **IP address** 
**name-to-IP** to intercept or redirect traffic.

**Vulnerable Protocols:
- **NetBIOS**: Can be spoofed to respond with fake IPs.
- **LLMNR**: Can be poisoned to steal usernames and NTLMv2 hashes. 
- **DNS**: Less common in local attacks, but can be hijacked if misconfigured. 
 
**Common Exploits:
- **LLMNR/NBT-NS spoofing** → attacker captures hashes for offline cracking.
- **Weak SMB credentials** on workgroups → easy access to shared files.
- **SMB relay attacks** → reuse captured credentials to access other systems.
 
 **Tools:
- **Responder**, **NBNSpoof**, **Metasploit**, **Pupy**

###  **`***SMB exploit***`**
there are many SMB exploit in the pass we can use **serachsploit smb** to search from exploit database.
SMB services use 2 tcp ports:
139 : SMB over NetBIOS
445 : SMB over TCP/IP

SMB related terms
- **RID (Relative Identifier)**:  
    Uniquely identifies (only within a domain) a user, group, system, or domain
- **SID (Security Identifier)**:  
    Uniquely identifies users and groups within the local domain. Globally unique so can also work between domains.
- **DC (Domain Controller)**:  
    A server that handles authentication and directory services in a Windows domain. Determines whether the users are allowed to access IT resources in the domain
- **LDAP (Lightweight Directory Access Protocol)**:  
    A protocol used to access and manage directory information, such as in Active Directory.
- **Workgroup**:  
    A peer-to-peer Windows network without centralized authentication or administration.
    
**Exploitation steps**
1. Gathering information same as in the chapter 3 using **nmap && enum4linux** to gather information about vulnerable SMB systems
2. Exploit!
	1. **Metasploit** to exploit known vulnerabilities
	2. **smbclient** : to access the target share files

**What we did in the lab**
1. **nmap -sN** find the host with open port 139 and 443
2. **enum4linux** the ip found in the nmap
	**-U** find configured users
	**-S** get a list of file shares
	**-G** get a list of the groups and their members
	**-P** list the password policies
	**-i** get a list of printers	
3. **smbclient** into the target/`<share folder>`  
	now we can access share files and folder using SMB protocal
	- you can upload/download file
	- list share directory
# Module 6 : Exploiting Web applications

**HTTP** is the most use protocol so it is good to learn about the basics of how it works
- HTTP server = web server, HTTP client = browser, API clients, proxies, and etc.
- Stateless protocol, no sequences of command in one sessions 

![[Pasted image 20250629230048.png]]
HTTP Proxy is both client and server, and can have many functionality
- Use TCP/IP protocal suite
- request and respond model
	- client --> request  --> server
	- client <-- respond <-- server
**tcpdump** command can be use to capture the packets from client to web server
**wireshark** also can be use to capture packets

#### **HTTP sturcture**
- **Method
	- **GET:** Retrieves information from the server  
	- **HEAD:** Basically the same as **GET** but returns only HTTP headers and no document body  
	- **POST:** Sends data to the server (typically using HTML forms, API requests, and so on)  
	- **TRACE:** Does a message loopback test along the path to the target resource  
	- **PUT:** Uploads a representation of the specified URI  
	- **DELETE:** Deletes the specified resource  
	- **OPTIONS:** Returns the HTTP methods that the server supports  
	- **CONNECT:** Converts the request connection to a transparent TCP/IP tunnel.**https://theartofhacking.org:8123/dir/test;id=89?name= omar&x=true**
- **The URI and the path-to-resource :** path of the *requested URL*
- **The request version-number** : HTTP version that client use
- **The user agent** : e.g. Firefox, Chrome the one that was used to access the website
- **Several other** ...
#### **HTTP response** : return with 3 digits status code, base on range
- 100 : Informational
- 200 : related to successful transactions
- 300 : related to HTTP redirections
- 400 : related to client errors
- 500 : related to servers errors
#### **HTTP URL structure**
- **scheme** : underlying protocol to be used (e.g. HTTP, FTP), scheme follow by **://**
- **host** : **IP address** or **DNS-based** of the web server
- **port** (optional) : port number that the web server is listens
- **path** : Path from the root directory ( real web server might use alias and cannot access directly from the root directory)
- **path-segment-params** (optional) : come after; name, value pair. It is rarely used in today url
- **query-string** (optional) : name/value pair represent parameters related to the request. Start the section with`" ? <key1> = <value1> && <key1> = <value2>"` 
e.g. **https://theartofhacking.org:8123/dir/test;id=89?name=omar&x=true** 

extra reading: **RESTful API**
### **Web Session Summary**
- A **web session** is a series of HTTP requests/responses between client and server, covering:
    - Pre-authentication
    - Authentication
    - Session management
    - Access control
    - Session termination
- Web apps use **sessions to track users**, even anonymous ones, storing settings like language and access rights.
- After login, the **session ID (token)** represents the user’s identity and must be:
    - **Long enough** (≥128 bits)
    - **Unpredictable** (≥256 bits of entropy via DRBG)
    - **Unique**
- Common session ID names (e.g., `PHPSESSID`, `JSESSIONID`) can **leak tech stack info**, so use generic names like `id`.
- **Session ID storage methods**:
    - **Cookies** (most common, with session/persistent types)j
    - **URL parameters** (discouraged — vulnerable to fixation/manipulation)
    - **POST/GET arguments**
- **Best practices**:
    - Use **encrypted channels** for entire session
    - Avoid putting session IDs in URLs
    - Use **non-persistent cookies** to clear sessions when the browser closes
    - **Validate all session IDs** to prevent injection/XSS attacks
it the attacker know the session ID then he/she can logins as that user without username or password
## Injection Based Vulnerabilities
Any web applications that accepts user input can be target of **Injection attacks**. The attacker input malicious codes into these input field (e.g. login credential). Without proper counter measure the attacker can exploit
**Type of injections**
- SQL injection vulnerabilities
- HTML injection vulnerabilities
- Command injection vulnerabilities
- Lightweight Directory Access Protocol (LDAP) injection vulnerabilities
### **`***SQL Injection***`**
Allow attacker to view, insert, delete, or modify records in a database. Attacker inject partial or complete SQL command into **web application input fields** or **URL** 

#### Basic SQL command
- **SELECT:** Used to obtain data from a database
- **UPDATE:** Used to update data in a database
- **DELETE:** Used to delete data from a database
- **INSERT INTO:** Used to insert new data into a database
- **CREATE DATABASE:** Used to create a new database
- **ALTER DATABASE:** Used to modify a database
- **CREATE TABLE:** Used to create a new table
- **ALTER TABLE:** Used to modify a table
- **DROP TABLE:** Used to delete a table
- **CREATE INDEX:** Used to create an index or a search key element
- **DROP INDEX:** Used to delete an index

Typically, SQL statements are divided into the following categories:

- Data definition language (DDL) statements
- Data manipulation language (DML) statements
- Transaction control statements
- Session control statements
- System control statements
- Embedded SQL statements
  
e.g. **SELECT * FROM * Customer WHERE ContactName LIKE** "Ninny". The "Ninny" part is from user input from the web page, attacker can modified the input to make the server to run additional command, that can modified or return secret from database, like **or 1=1** which is always true so it return the entire data base

*It is crutial to find where the web interact with database and which input field that the website use as parameters for the query*

#### SQL injection Categories
- In-band : obtain data using the same channel. The website
- out-of-band : sending the data from different channel (e.g. text,email)
- Blind(or inferential) : don't send or display data but can deduct from behavior of website

There are essentially five techniques that can be used to exploit SQL injection vulnerabilities:
- **Union operator:** This is typically used when an SQL injection vulnerability allows a **SELECT** statement to combine two queries into a single result or a set of results.
- **Boolean:** This is used to verify whether certain conditions are true or false.
- **Error-based technique:** This is used to force the database to generate an error in order to enhance and refine an attack (injection).
- **Out-of-band technique:** This is typically used to obtain records from the database by using a different channel. For example, it is possible to make an HTTP connection to send the results to a different web server or a local machine running a web service.
- **Time delay:** It is possible to use database commands to delay answers. An attacker may use this technique when he or she doesn’t get output or error messages from the application.
- **Stacked queries** : use semicolon(;) to execute many SQL command 
**database fingerprinting** error message give info about what SQL database are used*
- MYSQL
- Microsoft SQL
- Oracle SQL
To mitigate SQL injection 
- Static queries
- Parameterized queries
- Store procedure
read more : [_https://www.owasp.org/index.php/SQL_Injection_Prevention_Cheat_Sheet_](https://www.owasp.org/index.php/SQL_Injection_Prevention_Cheat_Sheet).
#### **Command Injetction**
not the same as code injection. Inject OS level commands, **192.168.78.6;cat /etc/passw**
*this is not popular anymore*

#### **LDAP Injection Summary:**
LDAP injection is an input validation flaw where attackers inject malicious queries into LDAP statements. Like SQL injection, it exploits unsanitized user input to manipulate the LDAP server. Successful attacks can lead to:
- **Authentication bypass** (e.g., skip login checks)
- **Information disclosure** (e.g., list internal directory data
LDAP is defined in **RFC 4511** and is commonly used for directory services.
Want a quick list of examples or defenses?

use CrackStation to crack easy hash