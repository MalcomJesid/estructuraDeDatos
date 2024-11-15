export interface Question {
  id: number;
  text: string;
  type: 'open' | 'single' | 'multiple';
  options?: string[];
}

export interface Survey {
  id: number;
  title: string;
  description: string;
  questions: Question[];
  createdAt: Date;
}

export interface Institution {
  id: number;
  name: string;
  location: string;
}

export interface SurveyConfiguration {
  id: number;
  surveyId: number;
  institutionId: number;
  grade: string;
  classroom: string;
  accessLink: string;
  qrCode: string;
}