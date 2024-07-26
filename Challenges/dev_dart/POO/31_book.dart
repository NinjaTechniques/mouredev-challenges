//https://github.com/DiscoDurodeRoer/curso-java-se/tree/master/ejercicios/02-poo

void main (){
  final Book book1 = Book(
    isbn: "565461897",
    title: "ALgorithms and Data Structures",
    numberOfPages: 120,
    autor: "Anonymous",
    isProvided: false
  );

  print("Title ${book1.title}");
  print("Pages ${book1.numberOfPages}");
  print("Is Provided? ${book1.getProvided}");

}


class Book {
  String isbn; 
  String title;
  int numberOfPages;
  String autor;
  bool isProvided;

  //Parameters with names
  Book({
    required this.isbn,
    required this.title,
    required this.numberOfPages,
    required this.autor,
    required this.isProvided
  });

  void set provided (bool value) { this.isProvided = value;}
  bool get getProvided => this.isProvided;
  String get getTitle => this.title;
  int get getNumberOfPages => this.numberOfPages;

  void toProvided (){ 
    if (this.isProvided) {
      this.isProvided = !this.isProvided;
    }    
  }

  void toReturn(){
    if (this.isProvided == false) {
      this.isProvided = !this.isProvided;
    }
  }

  double printBook (double price){
    return this.numberOfPages * price;
  }

}