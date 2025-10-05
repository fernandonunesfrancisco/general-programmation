nota1=float(input("Qual a sua primeira nota?"))
nota2=float(input("Qual a sua segunda nota?"))
nota3=float(input("Qual a sua terceira nota?"))

if nota1>=7 and nota2>=7 and nota3>=7:
    print("Aluno aprovado.")
else:
    if nota1<4 or nota2<4 or nota3<4:
        print("Aluno reprovado.")
    else:
        print("Aluno em recuperação.")