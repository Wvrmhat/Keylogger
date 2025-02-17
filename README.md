# Keylogger
Keylogger made during the ethical hacking course. Its use must be authorized and documented either for pen testing or red teaming in an organization. The following use cases are examples when a keylogger is used ethically. This has to be used in a controlled environment where the keylogger is removed after assessment.

## Use Cases

### Simulating insider threat attacks
In this case a pen tester would deploy a keylogger to see how easily an insider could steal sensitive company data. This is done to assess if employees store or type passwords insecurely. It is also done to see if security tools such as antivirus and endpoint detection and response (EDR) can detect and block it.

### Testing Endpoint Security
This is specifically for testing whether EDR or security information and event management (SIEM) tools can block keystroke logging. The goal here is to identify security flaws in endpoint systems and implement proper alerting mechanisms. 

### Red teaming and Adversary Simulation
A team of pen testers use keyloggers in different attack scenarios to simulate an advanced persistent threat (APT). This is done to determine how well security teams (such as SOC analysts) respond to multiple keylogging techniques. 


>[!Warning]
> This repository contains penetration testing tools developed in C++. These tools are intended strictly for educational and ethical hacking purposes. They should only be used in environments where you have explicit permission to test. I am not responsible for any misuse, damage, or legal issues arising from the use of this program. It is the responsibility of the user to comply with all applicable laws and regulations.
