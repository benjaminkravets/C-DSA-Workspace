import datetime

start_datetime = datetime.datetime(2023, 10, 13, 10, 27, 13)
end_datetime = datetime.datetime(2023, 10, 13, 12, 0, 0)

delta = end_datetime - start_datetime
delta_in_hours = delta.total_seconds() / 3600

print(delta_in_hours)