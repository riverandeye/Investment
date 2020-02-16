import Icharacter from "../interface";
import { Phantom } from "../Phantom";
import { Aran } from "../Aram";

export class CharacterFactory {
  public static createCharactor(type: string): Icharacter {
    switch (type) {
      case "PHANTOM":
        return new Phantom();
      case "ARAN":
        return new Aran();
    }
  }
}
