import numpy as np
import pandas as pd
from sklearn.preprocessing import MinMaxScaler
from sklearn.model_selection import train_test_split

class DataProcessor:
    def __init__(self, file_path, window_size):
        self.file_path = file_path
        self.window_size = window_size
        self.scaler = MinMaxScaler()
    
    def load_data(self):
        """Carga los datos desde un archivo CSV."""
        self.data = pd.read_csv(self.file_path)
        return self.data
    
    def preprocess_data(self):
        """Normaliza los datos y crea secuencias temporales."""
        data_scaled = self.scaler.fit_transform(self.data.values)
        X, y = self._create_sequences(data_scaled)
        return train_test_split(X, y, test_size=0.2, random_state=42, shuffle=False)
    
    def _create_sequences(self, data):
        """Crea secuencias de datos para la ventana temporal."""
        X, y = [], []
        for i in range(len(data) - self.window_size):
            X.append(data[i:i + self.window_size, :-1])  # Características
            y.append(data[i + self.window_size, -1])    # Generación (etiqueta)
        return np.array(X), np.array(y)

class LSTMModel:
    def __init__(self, input_shape, learning_rate=0.001):
        self.model = Sequential([
            LSTM(64, input_shape=input_shape, return_sequences=False),
            Dropout(0.2),
            Dense(16, activation='relu'),
            Dense(1, activation='linear')
        ])
        self.model.compile(optimizer=Adam(learning_rate=learning_rate), loss='mse', metrics=['mae'])
    
    def train(self, X_train, y_train, X_val, y_val, epochs=50, batch_size=32):
        """Entrena el modelo con los datos proporcionados."""
        self.history = self.model.fit(
            X_train, y_train,
            validation_data=(X_val, y_val),
            epochs=epochs,
            batch_size=batch_size,
            verbose=1
        )
    
    def evaluate(self, X_test, y_test):
        """Evalúa el modelo en el conjunto de prueba."""
        return self.model.evaluate(X_test, y_test)
    
    def predict(self, X):
        """Genera predicciones con el modelo."""
        return self.model.predict(X)
    
    def plot_training_history(self):
        """Visualiza el historial de entrenamiento."""
        import matplotlib.pyplot as plt
        plt.plot(self.history.history['loss'], label='Loss (train)')
        plt.plot(self.history.history['val_loss'], label='Loss (val)')
        plt.legend()
        plt.show()

class SolarForecastingApp:
    def __init__(self, data_file, window_size):
        self.processor = DataProcessor(data_file, window_size)
    
    def run(self):
        # Cargar y preprocesar datos
        print("Cargando y preprocesando datos...")
        self.processor.load_data()
        X_train, X_test, y_train, y_test = self.processor.preprocess_data()
        input_shape = (X_train.shape[1], X_train.shape[2])
        
        # Crear modelo LSTM
        print("Creando modelo LSTM...")
        self.model = LSTMModel(input_shape)
        
        # Entrenar modelo
        print("Entrenando modelo...")
        X_train, X_val, y_train, y_val = train_test_split(X_train, y_train, test_size=0.2, random_state=42, shuffle=False)
        self.model.train(X_train, y_train, X_val, y_val)
        
        # Evaluar modelo
        print("Evaluando modelo...")
        loss, mae = self.model.evaluate(X_test, y_test)
        print(f"Test Loss: {loss}, Test MAE: {mae}")
        
        # Visualizar historial de entrenamiento
        self.model.plot_training_history()
        
        # Generar predicciones
        y_pred = self.model.predict(X_test)
        self.plot_predictions(y_test, y_pred)
    
    def plot_predictions(self, y_test, y_pred):
        """Visualiza las predicciones frente a los valores reales."""
        import matplotlib.pyplot as plt
        y_test_inv = self.processor.scaler.inverse_transform(np.concatenate((np.zeros((y_test.shape[0], 3)), y_test.reshape(-1, 1)), axis=1))[:, -1]
        y_pred_inv = self.processor.scaler.inverse_transform(np.concatenate((np.zeros((y_pred.shape[0], 3)), y_pred), axis=1))[:, -1]
        plt.plot(y_test_inv, label='Real')
        plt.plot(y_pred_inv, label='Predicted')
        plt.legend()
        plt.show()

# EJECUTAR PROGRAMA
#if __name__ == "__main__":
    # Configurar parámetros del proyecto
    #data_file = "datos_fv.csv"  # Ruta al archivo de datos
    #window_size = 10            # Tamaño de la ventana temporal
    
    # Ejecutar la aplicación
    #app = SolarForecastingApp(data_file, window_size)
    #app.run()

