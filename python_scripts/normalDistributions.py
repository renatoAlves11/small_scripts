import scipy.stats as sc
import matplotlib.pyplot as plt
import numpy as np

def calculateCDF():
    opt = input('\n1 - Standard Normal Distribution\n' +
    '2 - Other Normal Distribution\n')

    if opt == '1':
        var = float(input('Input X for area <= X:'))
        print(f'Result = {sc.norm.cdf(var)}')
    if opt == '2':
        var = float(input('Input X for area <= X:'))
        loc = float(input('Input mean:'))
        sd = float(input('Input standard deviation:'))
        print(f'Result = {sc.norm.cdf(var, loc = loc, scale = sd)}')
        
def calculatePPF():
    opt = input('\n1 - Standard Normal Distribution\n' +
    '2 - Other Normal Distribution\n')

    if opt == '1':
        var = float(input('Input X for PPF(X)'))
        print(f'Result = {sc.norm.ppf(var)}')
    if opt == '2':
        var = float(input('Input X for PPF(X):'))
        loc = float(input('Input mean:'))
        sd = float(input('Input standard deviation:'))
        print(f'Result = {sc.norm.ppf(var, loc = loc, scale = sd)}')


def plotGraphic():

    # Define parameters
    opt = input('\n1 - Standard Normal Distribution\n' +
    '2 - Other Normal Distribution\n')
    if opt == '1':
        mean = 0
        std_dev = 1
    if opt == '2':
        mean = float(input('Input X mean:'))
        std_dev = float(input('Input standard deviation:'))

    num_samples = 10000

    # Generate random samples
    data = np.random.normal(loc=mean, scale=std_dev, size=num_samples)

    # Generate x-values for PDF
    x = np.linspace(mean - 4 * std_dev, mean + 4 * std_dev, 5000)
    y_pdf = sc.norm.pdf(x, loc=mean, scale=std_dev)

    # Plot histogram and overlay PDF
    plt.hist(data, bins=50, density=True, alpha=0.6, color='g', label='Sample Histogram')
    plt.plot(x, y_pdf, color='red', linewidth=2, label='Normal Distribution PDF')
    plt.title('Normal Distribution: Histogram with PDF Overlay')
    plt.xlabel('Value')
    plt.ylabel('Density')
    plt.legend()
    plt.grid(True)
    plt.show()

while True:
    opt = input('\nSelect what you want to do:\n'+
    '1 - calculate CDF(Cumulative Distribution Function)\n' +
    '2 - calculate PPF(Percentil Point Function)\n' + 
    '3 - Plot graphic for normal distribution\n' +
    '0 - Stop program execution\n')
    match opt:
        case '1': calculateCDF() #Calcular probabilidade de uma variável normal ser <= X
        case '2': calculatePPF()
        case '3': plotGraphic()
        case '0': break
