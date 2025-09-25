import pandas as pd
import matplotlib.pyplot as plt

df = pd.read_csv("log.csv") 

mouse_moves = df[df['evento'] == 'move']
clicks = df[df['evento'] == 'click']

plt.figure(figsize=(8,6))
plt.plot(mouse_moves['x'], mouse_moves['y'], linestyle='-', color='blue', alpha=0.5, label='Caminho do mouse')


if not clicks.empty:
    point_clicks = clicks[clicks['tipo_objeto'] == 'ponto']
    line_clicks  = clicks[clicks['tipo_objeto'] == 'linha']
    empty_clicks = clicks[clicks['tipo_objeto'] == 'nenhum']

    plt.scatter(point_clicks['x'], point_clicks['y'], color='green', label='Clique em ponto', s=50)
    plt.scatter(line_clicks['x'], line_clicks['y'], color='red', label='Clique em linha', s=50)


plt.gca().invert_yaxis()
plt.xlabel("X")
plt.ylabel("Y")
plt.title("Movimento do mouse com cliques e objetos")
plt.legend()
plt.grid(True)
plt.show()
