import pandas as pd
import numpy as np
import seaborn as sns #热力图
import itertools 
import datetime
import xlrd
import csv
import matplotlib.pyplot as plt
import statsmodels.api as sm 
from statsmodels.tsa.stattools import adfuller #ADF检验
from statsmodels.stats.diagnostic import acorr_ljungbox #白噪声检验
from statsmodels.graphics.tsaplots import plot_acf,plot_pacf #画图定阶
from statsmodels.tsa.arima_model import ARIMA #模型
from statsmodels.tsa.arima_model import ARMA #模型
from statsmodels.stats.stattools import durbin_watson #DW检验
from statsmodels.graphics.api import qqplot #qq图
from itertools import product

"""
def getData():
    data = open("D:/code/py/SN_ms_tot.csv", "r")
    d = open("D:/code/py/sunspotd.csv", "w")
    ls = []
    for line in data:
        t = line.split(";")
        ls.append([t[0]+'-'+t[1], t[3]])
    for line in ls:
        d.write(",".join(line)+'\n')
    data.close()

getData()

def data_handle():
    data = pd.read_csv("D:/code/py/sunspotd.csv")
    #print(data.describe())
    #print((data.isnull()).sum())
    #print((data.duplicated()).sum())

    def change_zero(x):
        if x == -1:
            return 0
        else :
            return x
    data['values'] = data['values'].apply(lambda x: change_zero(x))

    mean = data['values'].mean()
    def change_mean(x):
        if x == 0:
            return mean
        else:
            return x
    data['values'] = data['values'].apply(lambda x: change_mean(x))
    #保存处理过的数据
    data.to_csv('D:/code/py/newsunspotd.csv',index=0)
    print('new data is existing')
"""

 
def stationarity(timeseries): #平稳性处理

    #纯随机性检验（白噪声检验）
    p_value = acorr_ljungbox(timeseries, lags=1) 
    print (p_value)

    #ADF检验
    x = np.array(timeseries['values'])
    adftest = adfuller(x, autolag='AIC')
    print (adftest)



 
def determinate_order(timeseries): 
    
    #利用ACF和PACF判断模型阶数
    plot_acf(timeseries,lags=40) #延迟数
    plot_pacf(timeseries,lags=40)
    plt.show()


def getpq(timeseries):
    """
    ps = range(0, 6)
    qs = range(0, 6)
    parameters = product(ps, qs)
    parameter_list = list(parameters)
    ans = []

    best_aic = float('inf')

    for param in parameter_list:
        try:
            model = ARMA(timeseries, order = (param[0], param[1])).fit()
        except ValueError:
            print("参数错误")
            continue

        aic = model.aic
        if aic < best_aic:
            best_aic = aic
            ans.append([aic, (param[0], param[1])])
    
    print(ans)
    """
    model = ARMA(timeseries, order = (6, 0)).fit()

    predict_model = model.predict(start=0, end=3300)
    #shift_ts = t.shift(1).fillna(0)
    #diff_recover = predict_model.sum(shift_ts)
    
    timeseries.plot(color='blue', label='Original')
    predict_model.plot(color='red', label='Predict')
    

    #shift_ts.plot(color='blue', label='Original')
    #diff_recover.plot(color='red', label='Predict')
    plt.show()

csv_data = pd.read_csv("D:/code/py/newsunspotd.csv")
csv_df = pd.DataFrame(csv_data['values'])


stationarity(csv_df)
#determinate_order(csv_df)
#getpq(csv_df)








