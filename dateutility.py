import datetime
from datetime import datetime

def get_linux_timestamp(date_string):
    date_object = datetime.strptime(date_string, "%m/%d/%Y")
    linux_timestamp = datetime.timestamp(date_object)
    return linux_timestamp

# Example usage:

date_string = "10/12/2023"
linux_timestamp = get_linux_timestamp(date_string)

print(linux_timestamp)