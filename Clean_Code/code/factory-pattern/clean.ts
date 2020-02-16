import { CharacterFactory } from "./character/factory";

const aran = CharacterFactory.createCharactor("ARAN");
const phantom = CharacterFactory.createCharactor("PHANTOM");

console.log(aran.calculateAttackDamage());
console.log(phantom.calculateAttackDamage());
