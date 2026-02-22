1. Setup:
Tickets: 
Parent: 10 tickets
Child 1: 20 tickets
Child 2: 30 tickets
Child 3: 40 tickets

2. Workload:
For each process, a CPU bound loop that performs arithmetic operations was executed

3. Observed relative shares 
The Parent took 10% of CPU, child 1 tooks 20% CPU time, child 2 took 30% CPU time and child 3 40% CPU time.

4. Variance
Shorter runs shows higher variance due to the nature of the lottery scheduler. The lottery scheduler is probailistic by default. In terms of convergence (over longer runs) the shares converged to the expected values as the "randomness" averaged out.