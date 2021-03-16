  
import math
import random
from scipy.stats import binom
import array as arr
import numpy as np

#Program to compare the simulated and theoretical result for finding the probability such that at most two sixes are obtained when a dice is rolled 6 times
        
#Theoretical

#probability of getting a six in single roll of a dice
p=1/6

#THE dice is rolled 6 times in a single trial/simulation
rolls=6

#contains the possible no. of sixes in a single trial/simulation(six throws)
roll_vals=np.arange(0,7)

#array containing binomial distribution for each possible value( no. of sixes) in a single trial/simulation
binom_vals=[binom.pmf(r,rolls,p) for r in roll_vals]
theo_res=binom_vals[0]+binom_vals[1]+binom_vals[2]
print("Theoretical Result: ",theo_res)

#Simulations
  
trial_size = 100000
count = 0
for i in range(trial_size):
  six_count = 0
  for j in range(6):
    temp = random.randint(1,6)  #no. obtained on rolling a dice once
    if(temp == 6):
      six_count += 1           #counting no. of sixes in one trial
  if(six_count <= 2):
    count += 1           #total trials with at most two sixes
sim_res=count/trial_size
print("Simulated result: ",sim_res)

dif=abs(theo_res-sim_res)
print("Difference between theoretical and simulated result: ",dif)
                   




