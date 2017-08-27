import subprocess
from random import randint
import matplotlib.pyplot as plt

testcases = 20

factors = [1.2, 1.5, 1.75, 2, 3]

'''
#ADDITION
for _ in range(testcases):
	num1 = randint(-100000000000000000000, 100000000000000000000)
	num2 = randint(-100000000000000000000, 100000000000000000000)

	p = subprocess.Popen(['./test', '-a'], stdin=subprocess.PIPE, stdout=subprocess.PIPE)
	out, err = p.communicate(str(num1)+" "+str(num2))
	
	at_res = num1 + num2
	ob_res = out.split()[0]
	
	if(int(ob_res) == at_res):
		print "%-30s" % ("ADDITION Test case " + str(_ + 1) + ":") + " Passed" 
	else:
		print "Failed at testcase: " + str( _ + 1) + " For i/p: " + str(num1) + " + " + str(num2)
		print "Obtained output: " + ob_res + " " + "Actual output: " + str(at_res)
		exit(0)
		
print("\n")
'''

def test_insert(factor):
    p = subprocess.Popen(['./test', '-i', '100', str(factor)], stdin=subprocess.PIPE, stdout=subprocess.PIPE)
    out, err = p.communicate()

    times = list(map(float, out.split()))

    print(times)

    plt.plot(range(len(times)), times)
    plt.title('Insert with Factor: ' + str(factor))
    plt.xlabel('Current Size')
    plt.ylabel('Time')
    plt.show()
    
def test_delete():
    p = subprocess.Popen(['./test', '-d', '100', '1.2'], stdin=subprocess.PIPE, stdout=subprocess.PIPE)
    out, err = p.communicate()

    times = list(map(float, out.split()))

    print(times)

    plt.plot(range(len(times)), times)
    plt.show()
    
if __name__ == "__main__":

	for f in factors:
		test_insert(f)
