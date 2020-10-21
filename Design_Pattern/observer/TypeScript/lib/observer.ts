import Subject from "./subject";

export default interface Observer {
  update: (subject: Subject) => void;
}
