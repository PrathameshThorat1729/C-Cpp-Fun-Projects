# Calender 

A tool to get any date at your fingertips. get any month, year now at your terminal.

# How to use 

## Get Current Month and Year
to get current month
```bash 
$ ./cal 
```
and for whole year 
```bash 
$ ./cal -a 
``` 

## Get any Month 
```bash 
$ ./cal month <1-12>
``` 
1 - 12 for *January* to *December* 
and default year is current 

## Get any Year 
```bash 
$ ./cal year <year>
``` 
*year* is an integral value of that year
and default month is current month 
for whole year add '-a'
```bash 
$ ./cal year <year> -a
``` 
## Get any Month from any Year 
```bash 
$ ./cal month <1-12> year <year>
``` 
1 - 12 from *January* to *December* 

*year* is an integral value of that year

# Building 

## Compiling 
```bash 
$ make
``` 
or 
```bash 
$ make build 
``` 

## Cleaning
```bash 
$ make clean 
```