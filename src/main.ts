import { Component } from '@angular/core';
import { bootstrapApplication } from '@angular/platform-browser';
import { provideRouter, RouterOutlet, Routes } from '@angular/router';
import { LoginComponent } from './app/components/auth/login.component';
import { SurveyListComponent } from './app/components/survey/survey-list.component';
import { SurveyCreateComponent } from './app/components/survey/survey-create.component';

@Component({
  selector: 'app-root',
  standalone: true,
  imports: [RouterOutlet],
  template: `
    <div class="app-container">
      <header class="app-header">
        <h1>Sistema de gestión de encuestas</h1>
      </header>
      <main>
        <router-outlet></router-outlet>
      </main>
    </div>
  `,
  styles: [`
    .app-container {
      min-height: 100vh;
      background-color: #f5f5f5;
    }
    .app-header {
      background-color: #007bff;
      color: white;
      padding: 1rem 2rem;
      box-shadow: 0 2px 4px rgba(0,0,0,0.1);
    }
    main {
      padding: 2rem;
    }
  `]
})
export class App {
  name = 'Survey Management System';
}

// Definición del tipo para las rutas como 'Routes' para mejorar la verificación de tipos
const routes: Routes = [
  { path: '', redirectTo: '/surveys', pathMatch: 'full' },
  { path: 'login', component: LoginComponent },
  { path: 'surveys', component: SurveyListComponent },
  { path: 'surveys/create', component: SurveyCreateComponent }
];

// Configuración de la aplicación con rutas proporcionadas
bootstrapApplication(App, {
  providers: [
    provideRouter(routes)
  ]
});
