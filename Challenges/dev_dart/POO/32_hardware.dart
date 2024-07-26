void main () {

  final PC pc1 = PC(
    brand: "Asus", 
    model: "ROG", 
    ram: 16, 
    romCapacity: 100,
    romDisponibility: 50,
    isOn: true
  );

  
  final PC pc2 = PC(
    brand: "HP", 
    model: "31500", 
    ram: 8, 
    romCapacity: 420,
    romDisponibility: 350,
    isOn: false
  );


  print("Is equals? ${pc1.isEquals(pc1, pc2)}");
  print("");

  print("PC1 [Characteristics] : ");
  print(
    """
    Brand: ${pc1.getBrand}\n
    Model: ${pc1.getModel}\n
    Ram: ${pc1.getRam}\n
    Room: ${pc1.getRomCapacity}\n
    Diponibility: ${pc1.getRomDisponibility}\n
    Power? ${pc1.getIsOn}\n
    """
  );

  print("");
  print("PC2 [Characteristics] : ");
  print(
    """
    Brand: ${pc2.getBrand}\n
    Model: ${pc2.getModel}\n
    Ram: ${pc2.getRam}\n
    Room: ${pc2.getRomCapacity}\n
    Diponibility: ${pc2.getRomDisponibility}\n
    Power? ${pc2.getIsOn}\n
    """
  );


}


class PC {

  String brand;
  String model;
  int ram;
  double romCapacity;
  double romDisponibility;
  bool isOn;

  PC ({
    required this.brand,
    required this.model,
    this.ram = 4,
    this.romCapacity = 50,
    required this.romDisponibility,
    this.isOn = false
  });

  String get getBrand => this.brand;
  String get getModel => this.model;
  int get getRam => this.ram;
  double get getRomCapacity => this.romCapacity;
  double get getRomDisponibility => this.romDisponibility;
  bool get getIsOn => this.isOn;


  void power(bool isOn){
    if (isOn == false) {
      this.isOn = true;
    }

    return;
  }

  void shutdown (bool isOn){
    if (isOn) {
      this.isOn = false;
    }

    return;
  }

  void transfer (int quantityGB){
    if (this.isOn) {
      if (this.romDisponibility > this.romCapacity) {
        print("ERROR: Memory limited");
        return;
      }

      this.romDisponibility += quantityGB;
    }
  }

  void deleteFiles (int quantityDeleteGB){
     if (this.isOn) {
      if (this.romDisponibility > this.romCapacity) {
        this.romDisponibility = 0;
        print("Memory disponibility: 0 GB");
        return;
      }

      this.romDisponibility -= quantityDeleteGB;
    }
  }

  bool isEquals (PC pc1, PC pc2){
    if ((pc1.model == pc2.model) && pc1.brand == pc2.brand) {
      return true;
    }

    return false;
  }

}