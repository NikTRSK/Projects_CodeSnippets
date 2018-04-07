import sys
import re # Regular Expressions
import codecs # UniCode support
from pymongo import Connection # For DB Connection
from pymongo.errors import ConnectionFailure # For catching exeptions

def main():
  # MongoDB connection
  try:
    db_conn = Connection(host="localhost", port=27017) # speicify database parameters
    print "Connected to MongoDB successfully!"
  except ConnectionFailure, e:
    sys.stderr.write("Could not connect to MongoDB: %s" % e)
  
  # Load the database. If doesn't exist Mongo creates it
  db_target = db_conn["test"]

	# Open file
  file = codecs.open("test.txt", 'r', encoding='utf-8') # enable UTF-8 encoding

  # Define regex rules
  empid_rule = re.compile(r'[0-9]+\s')
  first_rule = re.compile(r'[a-z]+\s',re.IGNORECASE)
  last_rule = re.compile(r'[a-z]+\s(?=[0-9])',re.IGNORECASE)
  ts_start_rule = re.compile(r'[0-9]{4}-[0-9]{2}-[0-9]{2}\s[0-9]{2}:[0-9]{2}:[0-9]{2}\s')
  ts_end_rule = re.compile(r'(?<=[0-9-]\s)[0-9]{4}-[0-9]{2}-[0-9]{2}\s[0-9]{2}:[0-9]{2}:59\s')
  org_rule = re.compile(r'(?<=:[0-9]{2}\s)[a-z\s:_-]+(?=\s[a-z]+\s[0-9]{4})',re.IGNORECASE)
  netid_rule = re.compile(r'(?<=[a-zA-Z0-9:-_]\s)[a-z]+(?=\s[0-9\-](.*?)\s[0-9]+\.[0-9]+)')
  punch_in_rule = re.compile(r'[0-9-]+\s[0-9:-]+(?=\s[0-9-]+\s[0-9:-]+\s[0-9]+\.[0-9]+)')
  punch_out_rule = re.compile(r'[0-9-]+\s[0-9:-]+(?=\s[0-9]+\.[0-9]+)')
  hours_rule = re.compile(r'[0-9]+\.[0-9]+')

  next(file) # skip the header line
  for line in file:
    
    # grab the employee data
    employee = {
      "empid": empid_rule.match(line).group(0),
      "first": first_rule.search(line).group(0),
      "last": last_rule.search(line).group(0),
      "ts_start": ts_start_rule.search(line).group(0),
      "ts_end": ts_end_rule.search(line).group(0),
      "organization": org_rule.search(line).group(0),
      "netid": netid_rule.search(line).group(0),
      "punch_in": punch_in_rule.search(line).group(0),
      "punch_out": punch_out_rule.search(line).group(0),
      "hours": hours_rule.search(line).group(0)
    }

  # Insert document into DB
  db_target.timesheets.insert(employee, safe=True) # Insert record into timesheets collection

  # Close file
  f.close()

if __name__ == '__main__':
    main()