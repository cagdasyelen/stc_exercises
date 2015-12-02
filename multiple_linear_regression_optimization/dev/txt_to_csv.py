import csv

with open('fileName.txt') as fin, open('fileName.csv', 'w') as fout:
  o=csv.writer(fout)
  for line in fin:
    o.writerow(line.split())
