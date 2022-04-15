import numpy as np
from sklearn.neural_network import MLPClassifier
from sklearn.utils import shuffle
from sklearn.metrics import accuracy_score

x_size = 100000
train_size = int(0.7*x_size)
x = [_ for _ in range(x_size)]
x = shuffle(x)
x_np = np.array(x).reshape(-1, 1)
y_np = np.array([_%2 for _ in x])

x_np_train = x_np[:train_size]
y_np_train = y_np[:train_size]

x_np_test = x_np[train_size:]
y_np_test = y_np[train_size:]

CLS = MLPClassifier([100, 100])
CLS.fit(x_np_train, y_np_train)
y_predict = CLS.predict(x_np_test)

print(accuracy_score(y_np_test, y_predict))