CREATE TABLE Configurations(AIMKEY integer primary key,Layer integer not null, Type integer not null, Name text not null, Value text, Parent integer not null);
CREATE TABLE Contact(AIMKEY integer primary key, Ident text not null unique, Address text, Sex text, Age integer, Title Text, Phone text, Email text, foreign key(AIMKEY) references Element(AIMKEY));
CREATE TABLE Document(AIMKEY integer primary key, Ident text unique not null, File_Name text, foreign key(AIMKEY) references Element(AIMKEY));
CREATE TABLE Element(AIMKEY integer primary key, Entity_Type text, Short_Desc text, Long_Desc text, Foreign key(Entity_Type) references EntityType(Type));
CREATE TABLE EntityType(Type text primary key,Description text);
CREATE TABLE Project(AIMKEY integer primary key, Ident text unique not null, foreign key(AIMKEY) references Element(AIMKEY));
CREATE TABLE XRefElements(Parent_Key integer not null, Child_Key integer not null, XRef_Type text not null,
foreign key(Parent_Key) references Element(AIMKEY), foreign key(Child_Key) references Element(AIMKEY), foreign key(XRef_Type) references XRefType(XRef_ID));
CREATE TABLE XRefType(XRef_ID text primary key, Parent_Entity text not null, Child_Entity text not null, Description text,
foreign key(Parent_Entity) references EntityType(Type), foreign key(Child_Entity) references EntityType(Type));
CREATE VIEW View_AllDocument as
select E.AIMKEY, E.Entity_Type, E.Short_Desc, E.Long_Desc, D.Ident, D.File_Name
from Element as E, Document as D
where E.AIMKEY = D.AIMKEY;
CREATE VIEW View_AllProject as
select E.AIMKEY, E.Entity_Type, E.Short_Desc, E.Long_Desc, P.Ident
from Element E, Project P
where E.AIMKEY = P.AIMKEY;
CREATE VIEW View_XRef_Parent_Project AS
select p.AIMKEY, p.Entity_Type, p.Ident, p.Short_Desc, p.Long_Desc, x.Parent_Key, x.Child_Key, x.XRef_Type
from View_AllProject p, XRefElements x
where p.AIMKEY = x.Parent_Key;
