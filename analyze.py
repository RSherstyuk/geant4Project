import matplotlib.pyplot as plt

# Считываем данные
with open("data/output.txt", "r") as file:
    events = [line.strip() for line in file]

# Анализируем данные
event_ids = [int(line.split()[1]) for line in events]

# Строим график
plt.hist(event_ids, bins=50, color='blue', alpha=0.7)
plt.xlabel("Event ID")
plt.ylabel("Frequency")
plt.title("Distribution of Events")
plt.grid(True)
plt.show()
