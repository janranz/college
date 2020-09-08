## To actually do:
---

- ~~Figure out how to self-invoke or call function to clear / reset fields upon page load. [ toggleDisable(); ]~~
- ~~Set up results table. Since page is (hopefully) static, might need some way of refreshing table or a listener to display results. Start with figuring out what javascript:void(0) is *actually* doing in form action.~~
- ~~Add feature for user to delete a class from storage. Add input for Class ID and search array.~~
- ~~Consider a way to dump entire array (is the local storage used dealloc'd in some way?)~~
- ~~Figure out formatting the table / form (CSS)~~

---
- Functioning, but most likely not optimized. Something I can reflect on later as I get more familiar with these languages.
- Lacks style, but that is the least of my worries *right now*. Maybe some day... when I can intuitively float elements and know all the colors of the wind.
- Also going on the first bullet. Surely some corner case will break this and I didn't dive too deep in preventing them:
    * forces required inputs / time
    * forces class ID to uppercase (key)
    * populates DB from local storage, and re\-draws after almost every function call
    * packs inputs into an array of strings, which are then converted and passed on as key/value pairs for ease of access
    * Manually sets Lab fields to a '\-dash\-' over an empty string if checkbox is unchecked
    * forces upperCase to 'Delete Class' field to avoid key mis-match (If it's even case-sensitive to begin with).
---