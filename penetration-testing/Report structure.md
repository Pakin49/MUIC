1. **Executive summary** aim to create a summary for non technical reader, should include what is important in easy to understand language, include important information about what you found and what are recommended briefly, it would be nice to also put in the severity scale like
2. **Scope** : Explain the scope of testing
	1. what was include in the test? : which network, applications, services, devices was include or not include in the test,
	2. where the test was conduct: any time frame was the test allowed? 
	3. was there social engineering have been done?
	4. what type of testing was done? black box, white box, grey box, and what information were given to the penetration testing team
3. Methodology : How the test was done
	1. What tools were use in the process
	2. What tools are **prohibit to use in the process** 
	3. Might include picture of the result of each process, e.g. the result of the scanning tools.
	4. After scanning have we done any exploitation to validate the scanning result since most of the time the scanning result produce both false positive and false positive
	5. Is there any post exploitation have been done? e.g. we could access the secret share folder after gaining credential of one of the user, or even more severe gain admin privilege( privilege escalation) and alter some of the configuration of the server
4. Key finding: after explain what have been done, and how were the process from information gathering -> vulnerability scanning -> exploitation -> post exploitation, and we verified the result, this section summarize the key vulnerability that we found during the testing, we could include **CVE and CVSS** to add references and scoring system that people who might read the report later can do additional research about the vulnerability. The CVSS also help the reader know how severe is the vulnerabilities and then can prioritize which one to address the problem first.
5. Mitigation : explain the recommended method to fix the vulnerability which one is important that should be fixed imediatly and why? what are consequence and how attacker could abuse this security hole can use CIA to explain the consequence
	1. Confidentiality 
	2. Integrity
	3. Availability
6. Summary : summarize the point make above what vulnerability was found, how severe and which one that you recommend to fix first