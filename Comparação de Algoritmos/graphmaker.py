import numpy as np
import pandas as pd
import matplotlib.pyplot as plt

data = pd.read_csv('results.csv')

n = data['n'].values
insertion_time = data['InsertionSort'].values
merge_time = data['MergeSort'].values
quick_time = data['QuickSort'].values

n_squared = n ** 2
n_log_n = n * np.log2(n)

norm_insertion = insertion_time[-1] / n_squared[-1]
norm_merge = merge_time[-1] / n_log_n[-1]
norm_quick = quick_time[-1] / n_log_n[-1]

plt.figure(figsize=(15, 5))

plt.subplot(1, 3, 1)
plt.plot(n, insertion_time, 'o-', label='Insertion Sort (Experimental)')
plt.plot(n, norm_insertion * n_squared, '--', label='$O(n^2)$ (Teórica)', color='orange')
plt.xlabel('Tamanho do array (n)')
plt.ylabel('Tempo (s)')
plt.title('Insertion Sort')
plt.legend()

plt.subplot(1, 3, 2)
plt.plot(n, merge_time, 'o-', label='Merge Sort (Experimental)')
plt.plot(n, norm_merge * n_log_n, '--', label='$O(n \log n)$ (Teórica)', color='orange')
plt.xlabel('Tamanho do array (n)')
plt.ylabel('Tempo (s)')
plt.title('Merge Sort')
plt.legend()

plt.subplot(1, 3, 3)
plt.plot(n, quick_time, 'o-', label='Quick Sort (Experimental)')
plt.plot(n, norm_quick * n_log_n, '--', label='$O(n \log n)$ (Teórica)', color='orange')
plt.xlabel('Tamanho do array (n)')
plt.ylabel('Tempo (s)')
plt.title('Quick Sort')
plt.legend()

plt.tight_layout()
plt.show()
