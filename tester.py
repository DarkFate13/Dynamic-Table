import subprocess
from random import randint
import matplotlib.pyplot as plt
from itertools import accumulate

testcases = 20

factors = [1.2, 1.5, 1.75, 2, 3]

def test_insert(factor):
    p = subprocess.Popen(['./test', '-i', '100', str(factor)], stdin=subprocess.PIPE, stdout=subprocess.PIPE)
    out, err = p.communicate()

    times = list(map(float, out.split()))

    print('Maximium: ' + str(max(times)))

    plt.plot(range(len(times)), list(accumulate(times)), label=str(factor))
    
    
def test_delete(factor):
    p = subprocess.Popen(['./test', '-d', '100', str(factor)], stdin=subprocess.PIPE, stdout=subprocess.PIPE)
    out, err = p.communicate()

    times = list(map(float, out.split()))

    print('Maximium: ' + str(max(times)))
    
    plt.plot(range(len(times)), list(accumulate(times)), label=str(factor))
    
def test_ratio(factor, t1, t2):
    p = subprocess.Popen(['./test', '-r', '100', str(factor), str(t1), str(t2)], stdin=subprocess.PIPE, stdout=subprocess.PIPE)
    out, err = p.communicate()

    times = list(map(float, out.split()))

    print('Maximium: ' + str(max(times)))
    
    plt.plot(range(len(times)), list(accumulate(times)), label=str(factor))

if __name__ == "__main__":
    

    plt.xlabel('Current Size')
    plt.ylabel('Time')
    plt.title('Insert')
    
    print("INSERT")
    for f in factors:
        test_insert(f)
    
    plt.legend(loc="upper left")
    plt.show()
    plt.clf()

    plt.xlabel('Current Size')
    plt.ylabel('Time')
    plt.title('Delete')
    
    print("DELETE")
    for f in factors:
        test_delete(f)
	
    plt.legend(loc="upper left")
    plt.show()
    plt.clf()

    plt.xlabel('Operation Number')
    plt.ylabel('Time')
    plt.title('RATIO 4:3')
    
    print("RATIO 4:3")
    for f in factors:
        test_ratio(f, 4000000, 3000000);
    plt.legend(loc="upper left")
    plt.show()
    plt.clf()
	
    plt.xlabel('Operation Number')
    plt.ylabel('Time')
    plt.title('RATIO 4:2')
    
    print("RATIO 4:2")
    for f in factors:
        test_ratio(f, 4000000, 2000000);
    plt.legend(loc="upper left")
    plt.show()
    plt.clf()