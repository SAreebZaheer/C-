#Task 1

import pandas as pd
employee_data = {
    "Name": ["Alice", "Bob", "Charlie", "Diana", "Edward"],
    "Department": ["HR", "IT", "IT", "Marketing", "HR"],
    "Performance": [85, 90, 88, 92, 87]
}
dataframe = pd.DataFrame(employee_data)
average_performance = dataframe.groupby("Department")["Performance"].mean()
top_performers = dataframe[dataframe["Performance"] > 90]
dataframe, average_performance, top_performers

#Task 2

scores = pd.Series([78, 82, 90, 85, 88], index=["Alice", "Bob", "Charlie", "Diana", "Edward"])
first_three = scores[:3]
selected_range = scores["Charlie":"Edward"]
scores, first_three, selected_range