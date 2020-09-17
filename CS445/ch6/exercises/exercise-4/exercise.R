# Exercise 4: functions and conditionals

# Define a function `is_twice_as_long` that takes in two character strings, and 
# returns whether or not (e.g., a boolean) the length of one argument is greater
# than or equal to twice the length of the other.
# Hint: compare the length difference to the length of the smaller string
is_twice_as_long<-function(f,n)
{
  first_len<-nchar(f)
  sec_len<-nchar(n)
  smaller<-min(first_len,sec_len)
  diff<-abs(first_len - sec_len)
  
  diff>=smaller
}

# Call your `is_twice_as_long` function by passing it different length strings
# to confirm that it works. Make sure to check when _either_ argument is twice
# as long, as well as when neither are!
print(is_twice_as_long("needle","thread"))
print(is_twice_as_long("needle","threading the"))


# Define a function `describe_difference` that takes in two strings. The
# function should return one of the following sentences as appropriate
#   "Your first string is longer by N characters"
#   "Your second string is longer by N characters"
#   "Your strings are the same length!"
describe_difference<-function(f,n)
{
  diff<-(nchar(f)-nchar(n))
  if(diff > 0)
  {
    wo<-paste("first string is longer by: ",diff,"chars")
  }
  else if(diff < 0)
  {
    wo<-paste("second string is longer by",diff*-1,"chars")
  }
  else
  {
    wo<-"strings are the same len"
  }
  wo
}

# Call your `describe_difference` function by passing it different length strings
# to confirm that it works. Make sure to check all 3 conditions1
print(describe_difference("thread","needle"))
print(describe_difference("threads","and needles"))
print(describe_difference("threading the","needle"))