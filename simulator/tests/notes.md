# Notes on unit testing
[Source](https://www.typemock.com/unit-testing-with-c/)
Review types of testing:
let unit = a small self-contained group of classes and functions.
  Unit testing 
  -> Integration testing (how the unit reacts with other units) 
  -> System testing 
  -> Acceptance testing 

## Why unit test? 
- Find silly bugs early (before code reaches QA)
- Avoid regressions (clever bugs)
- Better design (encourages modularity)

## C++ unit testing 
- AAA pattern: Arrange, Act, Assert 
- Best practice: One object at a time. 
- Why so many rules: DRY, YAGNI, SRP, SOLID, KISS.
- Mocking: Creating an object that mimics the isolated object we want to test and give it expectations on how it
will be used. *If we create an object that interacts with a database, making the database a test dependency is not acceptable. We create an object that mimics the database interface.*

## GoogleTest
- assertion -> success, nonfatal failure, fatal failure
