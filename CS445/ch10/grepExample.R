# Exercise 3: working with built-in data sets

# Load R's "USPersonalExpenditure" dataset using the `data()` function
# This will produce a data frame called `USPersonalExpenditure`
data.frame("USPersonalExpenditure")

# The variable `USPersonalExpenditure` is now accessible to you. Unfortunately,
# it's not a data frame (it's actually what is called a matrix)
# Test this using the `is.data.frame()` function
is.data.frame(USPersonalExpenditure)

# Luckily, you can pass the USPersonalExpenditure variable as an argument to the
# `data.frame()` function to convert it a data farm. Do this, storing the
# result in a new variable
USPE<-data.frame(USPersonalExpenditure)
is.data.frame(USPE)

# What are the column names of your dataframe?
colnames(USPE)

## Consider: why are they so strange? Think about whether you could use a number
## like 1940 with dollar notation!

# What are the row names of your dataframe?
row<-rownames(USPE)

# Add a column "category" to your data frame that contains the rownames
USPE$category<-rownames(USPE)

# How much money was spent on personal care in 1940?
personalCare<-USPE["Personal Care","X1940"]
# print(personalCare)

# How much money was spent on Food and Tobacco in 1960?
foodBacco<-USPE[grep("^Foo*",row),"X1940"]
# print(foodBacco)

# What was the highest expenditure category in 1960?
highestCat<- USPE$category[USPE$X1960 == max(USPE$X1960)]
# print(highestCat)

# Define a function `lowest_category` that takes in a year as a parameter, and
# returns the lowest spending category of that year
lowestCat<-function(year)
{
  # cat<-sprintf("X%d",year)
  low<-USPE$category[USPE[,year] == min(USPE[,year])]
  return(low)
}

# Using your function, determine the lowest spending category of each year
# Hint: use the `sapply()` function to apply your function to a vector of years
result<- colnames(USPE) != "category"
print(result)
for(col in colnames(USPE))
{
  if(col != "category"){
    result<-sprintf("%s: %s",col,lowestCat(col))
    print(result)
  }
}
